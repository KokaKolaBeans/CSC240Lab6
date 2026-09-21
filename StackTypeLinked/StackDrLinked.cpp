// Linked Stack Driver
// Ivan Temesvari (Updated by Kazim Zaidi)
// Demonstrates ReplaceItem, and Identical, and various member, friend, and non-member non-friend functions of the StackTypeLinked class
// 9/20/2026
// Templated

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <random>
#include "StackTypeLinked.h"

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

void ReplaceItem(StackTypeLinked<ItemType> &stack, ItemType oldItem, ItemType newItem)
{
  // Function: Replaces all occurrences of oldItem with newItem.
  // Precondition: stack has been initialized.
  // Postcondition: Each occurrence of oldItem in stack has been replaced by newItem.

  StackTypeLinked<ItemType> tempStack;

  if (stack.IsEmpty())
  {
    cout << "stack is empty!\n\n";
    return;
  }

  while (!stack.IsEmpty())
  {

    if (stack.Top() == oldItem)
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
    stack.Push(tempStack.Top());
    tempStack.Pop();
  }
  return;
}

template <class ItemType>

bool Identical(const StackTypeLinked<ItemType> &stack1, const StackTypeLinked<ItemType> &stack2)
{
  // Function: Determines if two stacks are identical.
  // Preconditions: stack1 and stack2 have been initialized.
  // Postconditions: stack1 and stack2 are unchanged. Returns true if identical, false otherwise.

  bool identical = true;
  NodeType<ItemType> *locationStack1 = stack1.topPtr;
  NodeType<ItemType> *locationStack2 = stack2.topPtr;

  while (locationStack1 != nullptr && locationStack2 != nullptr) // same size
  {

    if (locationStack1->info != locationStack2->info)
    {

      identical = false;
      break;
    }
    locationStack1 = locationStack1->next;
    locationStack2 = locationStack2->next;
  }
  if (!(locationStack1 == nullptr && locationStack2 == nullptr))
  {
    identical = false;
  }

  return identical;
}

char getRandomLetter(bool uppercase = true)
{
  static random_device rd;
  static mt19937 gen(rd());
  uniform_int_distribution<> dis(0, 24); // Chooses letters 'A' to 'Y'; 'Z' indicates replacement

  char baseChar = uppercase ? 'A' : 'a';

  return static_cast<char>(baseChar + dis(gen));
}

int main()
{

  // Test with integer stack
  cout << "========== Testing Integer Stack ==========" << endl;
  try
  {
    StackTypeLinked<int> stack;
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
    StackTypeLinked<int> stack2;
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
  }
  catch (const FullStack &e)
  {
    cout << "Stack is full!" << endl;
  }
  catch (const EmptyStack &e)
  {
    cout << "Stack is empty!" << endl;
  }

  // Test the Print function.

  StackTypeLinked<char> myStack;

  myStack.Push('A');
  myStack.Push('K');
  myStack.Push('G');
  myStack.Push('K');
  myStack.Print();
  // Test copy constructor
  StackTypeLinked<char> newStack(myStack);
  newStack.Print();
  StackTypeLinked<char> anotherStack;

  anotherStack.Push('B');
  anotherStack.Push('C');
  anotherStack.Push('D');
  anotherStack.Push('E');
  anotherStack.Print();
  // Test operator=
  anotherStack = newStack;
  anotherStack.Print();

  cout << "\n========== ReplaceItem ==========" << endl
       << endl;

  StackTypeLinked<char> stackA;

  cout << "***stackA (empty)***" << endl
       << endl;

  stackA.Print();
  cout << endl;

  cout << "***ReplaceItem(stackA, 'A', 'Z') error message***" << endl
       << endl;

  ReplaceItem(stackA, 'A', 'Z');

  cout << "***stackA (filled w/ random)***" << endl;

  for (int k = 0; k < 10; k++)
  {
    char c = getRandomLetter(true);
    stackA.Push(c);
  }

  stackA.Print();

  ReplaceItem(stackA, 'A', 'Z');

  ReplaceItem(stackA, 'B', 'Z');

  ReplaceItem(stackA, 'C', 'Z');
  cout << endl;

  cout << "***ReplaceItem(stackA, 'A', 'Z')***" << endl;

  cout << "***ReplaceItem(stackA, 'B', 'Z');***" << endl;

  cout << "***ReplaceItem(stackA, 'C', 'Z')***" << endl
       << endl;

  stackA.Print();

  cout << "\n========== Identical ==========" << endl
       << endl;

  StackTypeLinked<char> stackC;

  StackTypeLinked<char> stackD;

  for (int k = 0; k < 10; k++)
  {
    int n = getRandomLetter(true);
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

  cout << "***stackC: one additional random char added***" << endl
       << endl;

  stackC.Push(getRandomLetter(true));

  id = Identical(stackC, stackD);

  s = id ? "true" : "false";

  cout << "stackC and stackD Identical: " << s << endl
       << endl;

  return 0;
}

// g++ -std=c++17 StackDrLinked.cpp -o StackDrLinked &&./StackDrLinked