// Test driver
// Ivan Temesvari
// Updated operator[]
// 2/17/2022
// Templated version

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>
#include <time.h>
#include "StackType.h"

using namespace std;

template <class ItemType>

void ReplaceItem(StackType<ItemType> &stack, ItemType oldItem, ItemType newItem)
{
    // Function: Replaces all occurrences of oldItem with newItem.
    // Precondition: stack has been initialized.
    // Postcondition: Each occurrence of oldItem in stack has been replaced by newItem.

    StackType<ItemType> tempStack; // figure out how to provide size of main stack to tempStack constructor
    ItemType tempItem;

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

// //   Function: Determines if two stacks are identical.
// // Preconditions: stack1 and stack2 have been initialized.
// // Postconditions: stack1 and stack2 are unchanged. Returns true if identical, false otherwise.

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

int main()
{

    StackType<int> stack;
    stack.Push(4);
    stack.Push(4);
    stack.Push(5);
    stack.Push(4);
    stack.Push(3);
    stack.Push(4);

    // stack.Print();

    cout << endl
         << endl;

    ReplaceItem(stack, 4, 10);

    // stack.Print();

    StackType<int> stackA;
    StackType<int> stackB;

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int k = 0; k < 4; k++)
    {
        int n = rand() % 5;
        stackA.Push(n);

        // stackA.Push(rand() % 101);
    }

    for (int k = 0; k < 4; k++)
    {
        int n = rand() % 5;
        stackB.Push(n);

        // stackA.Push(rand() % 101);
    }

    // make them dif sizes
    // stackB.Pop();
    // stackB.Pop();
    // stackA.Push(200);
    // for (int k = 0; k < 4; k++)
    // {
    //     // stackB.Push(rand() % 101);
    // }

    cout << "stack A: " << endl;

    stackA.Print();

    cout << "stack B: " << endl;

    stackB.Print();

    bool id = Identical(stackA, stackB);

    cout << "Stack A and Stack B Identical: " << id << endl;

    // stack2.ReplaceItem(stack2, -5, 5);

    // stack.Push(4);
    // stack.Push(4);
    // stack.Push(5);
    // stack.Push(4);
    // stack.Push(3);
    // stack.Push(4);

    ReplaceItem(stackA, 4, 10); // replace all occurances of '4' with '10'

    ReplaceItem(stackB, 2, 100);
    stackA.Print();
    stackB.Print();

    // g++ -std=c++17 stackTest.cpp -o StackProgram && ./StackProgram

    return 0;
}

// g++ -std=c++17 stackTest.cpp -o StackProgram