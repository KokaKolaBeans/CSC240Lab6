// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "StackTypeLinked.h"

using namespace std;

template <class ItemType>

void ReplaceItem(StackTypeLinked<ItemType> &stack, ItemType oldItem, ItemType newItem)
{
    StackTypeLinked<ItemType> tempStack;
    ItemType tempItem;

    while (topPtr.next != nullptr)
    {

        tempItem = stack.Top(); // returns current Top ItemType

        if (tempItem.info == newItem.info)
        {
            stack.Pop();
            stack.Push(newItem);
        }

        tempStack.Push(tempItem);
    }

    while (tempStack.Top().next != nullptr)
    {
        tempItem = tempStack.Top();
        stack.Push(tempItem);
    }
    return;
}

int main()
{
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

    ReplaceItem(myStack, 'A', 'B');

    // Test operator=
    anotherStack = newStack;
    anotherStack.Print();
    return 0;
}

// g++ -std=c++17 stackTest.cpp -o StackProgram && ./StackProgram