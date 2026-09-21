// Array-Based Stack Driver
// Ivan Temesvari (Updated by Kazim Zaidi)
// Demonstrates ReplaceItem, and Identical, and various member, friend, and non-member non-friend functions fo the StackType class
// 9/20/2026
// Templated

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include "StackTypeArray.h"

using namespace std;

// =======================================================================================================================================
/*
                                        Design and Documentation Question 1

Moving elements from the original stack to the temporary stack naturally reverses their order. When items are moved back
to the original stack, their order is reversed once again, preserving the original ordering of the stack. This is facilitated
by the Last-In-First-Out behavior of the stack ADT herein used. In the first while-loop, stack element k (the top) becomes tempStack
element 1; stack element k-1 becomes tempStack element 2; and, eventually, stack element 1 (the bottom) becomes tempStack element k,
where k represents the total number of elements in the stack. When items are moved from the tempStack back to the main stack, this
reversal happens a second time, restoring element j to position j.

During the initial transfer, every popped element is evaluated. If it matches the target, the replacement item is pushed to the temporary
stack in its place. Because this substitution happens sequentially during the first transfer, the new item occupies the exact same relative
position when the stack is restored.

*/
// =======================================================================================================================================

template <class ItemType>

void ReplaceItem(StackType<ItemType> &stack, ItemType oldItem, ItemType newItem)
{
  // Function: Replaces all occurrences of oldItem with newItem.
  // Precondition: stack has been initialized.
  // Postcondition: Each occurrence of oldItem in stack has been replaced by newItem.

  StackType<ItemType> tempStack;
  ItemType tempItem;

  if (stack.IsEmpty())
  {
    cout << "Stack is empty!\n\n";
    return;
  }

  while (!stack.IsEmpty())
  {
    if (stack.Top() == oldItem) // new target is replaced in-place
    {
      tempStack.Push(newItem);
    }

    else
    {
      tempStack.Push(stack.Top());
    }

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

template <class ItemType>

bool Identical(const StackType<ItemType> &stack1, const StackType<ItemType> &stack2)

//   Function: Determines if two stacks are identical.
// Preconditions: stack1 and stack2 have been initialized.
// Postconditions: stack1 and stack2 are unchanged. Returns true if identical, false otherwise.

{
  bool identical = true;

  if (stack1.top != stack2.top) // if stack1.top == stack2.top, they are the same size

  {
    identical = false;
    return identical;
  }

  for (int k = stack1.top; k >= 0; k--)
  {
    if (stack1.items[k] != stack2.items[k])
    {
      identical = false;
      break;
    }
  }

  return identical;
}

int main()
{
  // Test with integer stack
  cout << "========== Testing Integer Stack ==========" << endl;
  try
  {
    StackType<int> stack;
    stack.Print();
    stack.Push(4);
    stack.Push(4);
    stack.Push(5);
    stack.Push(4);
    stack.Push(3);
    stack.Push(4);
    stack.Print();

    // --- RUBRIC REQUIREMENT INSERTION ---

    cout << "\nReplacing 4 with 8..." << endl;
    ReplaceItem(stack, 4, 8);
    stack.Print();

    cout << "Building second identical stack..." << endl;
    StackType<int> stack2;
    stack2.Push(8);
    stack2.Push(8);
    stack2.Push(5);
    stack2.Push(8);
    stack2.Push(3);
    stack2.Push(8);

    bool isId = Identical(stack, stack2);
    cout << "Stacks are identical: " << (isId ? "true" : "false") << endl;

    // ------------------------------------

    cout << "The iterator over the stack items:\n";
    // Now try a range-based loop over a StackType;
    // automatically uses the StackTypeIterator and the operator*
    for (auto i : stack)
    {
      cout << i << endl; // i is now the actual item value
    }
  }
  catch (const FullStack &e)
  {
    cout << "Stack is full!" << endl;
  }
  catch (const EmptyStack &e)
  {
    cout << "Stack is empty!" << endl;
  }

  // Test with double stack
  cout << "\n========== Testing Double Stack ==========" << endl;
  try
  {
    StackType<double> doubleStack;
    doubleStack.Push(3.14);
    doubleStack.Push(2.71);
    doubleStack.Push(1.41);
    doubleStack.Print();
    cout << "Top element: " << doubleStack.Top() << endl;
    doubleStack.Pop();
    cout << "After pop:" << endl;
    doubleStack.Print();
  }
  catch (const FullStack &e)
  {
    cout << "Stack is full!" << endl;
  }
  catch (const EmptyStack &e)
  {
    cout << "Stack is empty!" << endl;
  }

  // Test with string stack
  cout << "\n========== Testing String Stack ==========" << endl;
  try
  {
    StackType<string> stringStack(10);
    stringStack.Push("Hello");
    stringStack.Push("World");
    stringStack.Push("C++");
    stringStack.Push("Templates");
    stringStack.Print();
    cout << "Iterating with range-based for:" << endl;
    for (auto str : stringStack)
    {
      cout << "  " << str << endl;
    }
  }
  catch (const FullStack &e)
  {
    cout << "Stack is full!" << endl;
  }
  catch (const EmptyStack &e)
  {
    cout << "Stack is empty!" << endl;
  }

  // Range-based for loop for an array of integers.
  cout << "\n========== Testing Array Iterator ==========" << endl;
  cout << "The iterator over the array items:\n";
  int numbers[] = {4, 5, 6, 7, 8, 9};
  for (auto num : numbers)
  {
    cout << num << endl;
  }

  // Test with vector
  cout << "\n========== Testing Vector ==========" << endl;
  std::vector<int> myvector;
  for (int i = 1; i <= 5; i++)
    myvector.push_back(i);

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  for (auto num : myvector)
  {
    std::cout << ' ' << num;
  }
  std::cout << '\n';

  cout << "\n========== ReplaceItem ==========" << endl
       << endl;

  StackType<int> stackA;

  cout << "***stackA (empty)***" << endl
       << endl;
  stackA.Print();
  cout << endl;
  cout << "***ReplaceItem(stackA, 4, 400) error message***" << endl
       << endl;

  ReplaceItem(stackA, 4, 400);

  cout << endl;

  srand(static_cast<unsigned int>(time(nullptr)));

  for (int k = 0; k < 10; k++)
  {
    stackA.Push(rand() % 5);
  }

  cout << "***stackA (filled w/ random)***" << endl
       << endl;

  stackA.Print();

  ReplaceItem(stackA, 1, 100);

  ReplaceItem(stackA, 4, 400);

  ReplaceItem(stackA, 7, 700);

  cout << "***ReplaceItem(stackA, 1, 100)***" << endl;

  cout << "***ReplaceItem(stackA, 4, 400)***" << endl;

  cout << "***ReplaceItem(stackA, 7, 700)***" << endl
       << endl;

  stackA.Print();

  cout << "\n========== Identical ==========" << endl
       << endl;

  StackType<int> stackC;

  StackType<int> stackD;

  for (int k = 0; k < 10; k++)
  {
    int n = rand() % 5;
    stackC.Push(n);
    stackD.Push(n);
  }

  cout << "***stackC***" << endl;
  stackC.Print();

  cout << "***stackD = stackC***" << endl;
  stackD.Print();
  cout << endl;

  bool id = Identical(stackC, stackD);

  string s = id ? "true" : "false";

  cout << "stackC and stackD Identical: " << s << endl
       << endl;

  cout << "***stackC: one additional random int added***" << endl
       << endl;

  stackC.Push(rand() % 5);

  id = Identical(stackC, stackD);

  s = id ? "true" : "false";

  cout << "stackC and stackD Identical: " << s << endl
       << endl;

  return 0;
}

// g++ -std=c++17 StackDrArray.cpp -o StackDrArray && ./StackDrArray