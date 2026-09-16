#ifndef STACK_TYPE_H
#define STACK_TYPE_H
#include "StackTypeIterator.h"
#include <iostream>
using namespace std;

// Class specification for templated Stack ADT
// Edit: Templated version

class FullStack
{
};
// Exception class thrown by Push when stack is full.

class EmptyStack
{
};
// Exception class thrown by Pop and Top when stack is empty.

class OutOfBounds
{
};
// Exception class thrown by operator[] when a bad index is attempted.

template <typename ItemType>
class StackType
{
public:
  StackType(int max); // max is stack size
  StackType();        // Default size is 500

  // Rest of the prototypes go here.
  bool IsFull() const;
  // Function: Determines whether the stack is full.
  // Pre:  Stack has been initialized.
  // Post: Function value = (stack is full)

  bool IsEmpty() const;
  // Function: Determines whether the stack is empty.
  // Pre:  Stack has been initialized.
  // Post: Function value = (stack is empty)

  void Push(ItemType item);
  // Function: Adds newItem to the top of the stack.
  // Pre:  Stack has been initialized.
  // Post: If (stack is full), FullStack exception is thrown;
  //     otherwise, newItem is at the top of the stack.

  void Pop();
  // Function: Removes top item from the stack.
  // Pre:  Stack has been initialized.
  // Post: If (stack is empty), EmptyStack exception is thrown;
  //     otherwise, top element has been removed from stack.

  ItemType Top();
  // Function: Returns a copy of top item on the stack.
  // Pre:  Stack has been initialized.
  // Post: If (stack is empty), EmptyStack exception is thrown;
  //     otherwise, top element has been removed from stack.

  ~StackType();
  // Destructor. Reallocate the memory reserved for ItemType* items.

  void Print();
  // Print the stack

  ItemType &operator[](int);

  StackTypeIterator<ItemType> begin();
  StackTypeIterator<ItemType> end();

  void ReplaceItem(StackType &stack, ItemType oldItem, ItemType newItem);
  // Function: Replaces all occurrences of oldItem with newItem.
  // Precondition: stack has been initialized.
  // Postcondition: Each occurrence of oldItem in stack has been replaced by newItem.

  friend bool Identical(const StackType &stack1, const StackType &stack2)

  //   Function: Determines if two stacks are identical.
  // Preconditions: stack1 and stack2 have been initialized.
  // Postconditions: stack1 and stack2 are unchanged. Returns true if identical, false otherwise.

  {
    bool identical = true;

    int stack1Top = stack1.top;
    int stack2Top = stack2.top;

    if (stack1Top != stack2Top)
    {
      identical = false;
      return identical;
    }

    // stack1.top == stack2.top (they are the same size)

    int *ptrStack1 = stack1.items; // pts to top of stack1
    int *ptrStack2 = stack2.items; // pts to top of stack 2

    for (int k = stack1Top; k >= 0; k--)
    {
      if (*ptrStack1 != *ptrStack2)
      {
        identical = false;
      }
    }

    return identical;
  };

private:
  int top;
  int maxStack;    // Maximum number of stack items.
  ItemType *items; // Pointer to dynamically allocated memory.
};

///////////////////////////////////////////////////////////////////////////////
//
// IMPLEMENTATION
//
///////////////////////////////////////////////////////////////////////////////

// Overload the operator[]
template <typename ItemType>
ItemType &StackType<ItemType>::operator[](int index)
{
  if (index < 0 || index > top)
  {
    throw OutOfBounds();
  }
  else
  {
    return items[index];
  }
}

template <typename ItemType>
StackType<ItemType>::StackType(int max)
{
  maxStack = max;
  top = -1;
  items = new ItemType[maxStack]; // I believe this returns a pointer to the beginning of this allocated block of memory
}

template <typename ItemType>
StackType<ItemType>::StackType()
{
  maxStack = 500;
  top = -1;
  items = new ItemType[maxStack];
}

template <typename ItemType>
bool StackType<ItemType>::IsEmpty() const
{
  return (top == -1);
}

template <typename ItemType>
bool StackType<ItemType>::IsFull() const
{
  return (top == maxStack - 1);
}

template <typename ItemType>
void StackType<ItemType>::Push(ItemType newItem)
{
  if (IsFull())
    throw FullStack();
  top++;
  items[top] = newItem;
}

template <typename ItemType>
void StackType<ItemType>::Pop()
{
  if (IsEmpty())
    throw EmptyStack();
  top--;
}

template <typename ItemType>
ItemType StackType<ItemType>::Top()
{
  if (IsEmpty())
    throw EmptyStack();
  return items[top];
}

// template <typename ItemType>
// ItemType StackType<ItemType>::Top const();

template <typename ItemType>
StackType<ItemType>::~StackType()
{
  delete[] items;
}

template <typename ItemType>
StackTypeIterator<ItemType> StackType<ItemType>::begin()
{
  StackTypeIterator<ItemType> it(0, items);
  cout << "The stack iterator initializes." << endl;
  return it;
}

template <typename ItemType>
StackTypeIterator<ItemType> StackType<ItemType>::end()
{
  StackTypeIterator<ItemType> it(top + 1, items);
  return it;
}

template <typename ItemType>
void StackType<ItemType>::Print()
{
  cout << "Top:" << endl;
  if (!IsEmpty())
  {
    for (StackTypeIterator<ItemType> it = begin(); it != end(); ++it)
    {
      cout << *it << endl;
    }
  }
  cout << ":Bottom" << endl;
}

template <typename ItemType>

void StackType<ItemType>::ReplaceItem(StackType &stack, ItemType oldItem, ItemType newItem)
{
  StackType tempStack; // figure out how to provide size of main stack to tempStack constructor

  ItemType tempItem;

  while (!stack.IsEmpty())
  {

    if (stack.Top() == oldItem) // new target is replaced in-place
    {
      stack.Pop();
      stack.Push(newItem);
    }
    tempItem = stack.Top(); // returns copy
    tempStack.Push(tempItem);
    stack.Pop();
  }

  while (!tempStack.IsEmpty())

  {
    tempItem = tempStack.Top();
    stack.Push(tempItem);
    tempStack.Pop();
  }
  return;
}

#endif
