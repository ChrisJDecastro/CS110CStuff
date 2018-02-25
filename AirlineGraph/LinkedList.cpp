//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class LinkedList.
 @file LinkedList.cpp */

#include "LinkedList.h"  // Header file
#include <cassert>
#include <string>
#include <cstdlib>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), tailPtr(nullptr), itemCount(0)
{
   headPtr = nullptr;
   tailPtr = nullptr;
   itemCount = 0;
}  // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) : itemCount(aList.itemCount)
{
   Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original chain

   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original list is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item 
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);  
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr); 
         
         // Advance pointer to new last node      
         newChainPtr = newChainPtr->getNext();
         
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert)
   {
      // Create a new node containing the new entry 
      Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);  

      if (isEmpty()) // Special case: Inserting if list is empty
      {
        // Set the head pointer
        newNodePtr->setNext(headPtr);
        headPtr = newNodePtr;

        // Set the tail pointer
        newNodePtr->setNext(tailPtr);
        tailPtr = newNodePtr;
      }
      else if (newPosition == 1) // Special case: Inserting at beginning of list
      {
        Node<ItemType>* oldPtr = getNodeAt(newPosition);

        newNodePtr->setNext(headPtr);
        headPtr = newNodePtr;

        newNodePtr->setPrev(nullptr);

        oldPtr->setPrev(newNodePtr);

        newNodePtr->setNext(oldPtr);

      }
      else if (newPosition == itemCount+1) // Special case: Inserting at end of list
      {
        Node<ItemType>* oldPtr = getNodeAt(itemCount);

        newNodePtr->setPrev(oldPtr);

        newNodePtr->setNext(nullptr);

        oldPtr->setNext(newNodePtr);

        newNodePtr->setNext(tailPtr);
        tailPtr = newNodePtr;
      }
      else // Case: Inserting in middle of list
      {
        Node<ItemType>* prevNodePtr = getNodeAt(newPosition-1);
        Node<ItemType>* nextNodePtr = getNodeAt(newPosition);

        prevNodePtr->setNext(newNodePtr);

        nextNodePtr->setPrev(newNodePtr);
 
        newNodePtr->setPrev(prevNodePtr);

        newNodePtr->setNext(nextNodePtr);
      }

      itemCount++;  // Increase count of entries
   }  // end if

   return ableToInsert;
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      Node<ItemType>* curPtr = nullptr;
      if (position == 1)
      {
         // Remove the first node in the chain
         curPtr = headPtr; // Save pointer to node
         headPtr = headPtr->getNext();
      }
      else 
      {
         // Find node that is before the one to delete
         Node<ItemType>* prevPtr = getNodeAt(position - 1);
         
         // Point to node to delete
         curPtr = prevPtr->getNext();
         
         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prevPtr->setNext(curPtr->getNext());
         if(curPtr->getNext())
         {
           curPtr->getNext() ->setPrev(prevPtr);
         }
         else
         {
           prevPtr->setNext(nullptr);
           tailPtr = prevPtr;
         }
      }  // end if
      
      // Return node to system
      curPtr->setNext(nullptr);
      delete curPtr;
      curPtr = nullptr;
      
      itemCount--;  // Decrease count of entries
   }  // end if
   
   return ableToRemove;
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
   while (!isEmpty())
      remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      string message = "getEntry() called with an empty list or "; 
      message  = message + "invalid position.";
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end getEntry

template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   if (ableToSet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      nodePtr->setItem(newEntry);
   }
   else
   {
      string message = "setEntry() called with an invalid position."; 
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end setEntry

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
   // Debugging check of precondition
  assert( (position >= 1) && (position <= itemCount) );
   
  Node<ItemType>* curPtr = headPtr;
      
  if(position == 1)
  {
    curPtr = headPtr;
  }
  else
  {
    curPtr = getNodeAtRecursive(position-1,curPtr);
  }

  return curPtr;
}  // end getNodeAt

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>:: getNodeAtRecursive(int position, Node<ItemType>*curPtr) const
{
  if(position == 1)
  {
    curPtr = curPtr->getNext();
  }
  else
  {
    curPtr = getNodeAtRecursive(position-1, (curPtr->getNext()));
  }
  return curPtr;

}

template<class ItemType>
void LinkedList<ItemType>::reverse()
{
  // reverse the prev/next pointers for every entry in the list
  Node<ItemType>* tempPtr = nullptr;
  Node<ItemType>* curPtr = headPtr;

  while (curPtr != NULL)
  {
    tempPtr = curPtr->getNext(); // get next node
    curPtr->setNext(curPtr->getPrev()); // swap next with prev in current node
    curPtr->setPrev(curPtr->getNext()); // swap prev with next in current node

    // eventually get to null pointer at end of list
    // CASE: last item in list
    if (tempPtr == NULL)
    {
      // swap head pointer with tail pointer
      headPtr = tailPtr;

      // set tail pointer equal to the head pointer
      tailPtr = curPtr;
    }
    // set curPtr to what what will be the previous node
    curPtr = tempPtr;
  }
} // end reverse




// End of implementation file.  To get this to compile on hills,
// add definitions of template types we will use (int or string now,
// add more types if necessary)
template class LinkedList<int>;
template class LinkedList<std::string>;
