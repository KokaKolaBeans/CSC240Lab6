// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <random>
#include "StackTypeLinked.h"

using namespace std;

template <class ItemType>

void ReplaceItem(StackTypeLinked<ItemType> &stack, ItemType oldItem, ItemType newItem)
{
    // cout << "block 1 - ENTER FUNCTION" << endl;

    StackTypeLinked<ItemType> tempStack;
    // ItemType tempItem;

    while (!stack.IsEmpty())
    {
        // tempItem = stack.Top();
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

char getRandomLetter(bool upercase = true)
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 25);

    char baseChar = &uppercase ? 'A' : 'a';

    return static_cast<char>(baseChar + dis(gen));
}

int main()
{
    // Test the Print function.
    StackTypeLinked<char> stackA;

    StackTypeLinked<char> stackB;

    for (int k = 0; k < 100; k++)
    {
        stackA.Push(getRandomLetter(true));
        // stackA.Push('D');
    }

    for (int k = 0; k < 10; k++)
    {
        stackB.Push(getRandomLetter(true));
    }

    stackA.Print();

    ReplaceItem(stackA, 'A', 'Z');
    ReplaceItem(stackA, 'B', 'Z');
    ReplaceItem(stackA, 'C', 'Z');
    ReplaceItem(stackA, 'D', 'Z');
    ReplaceItem(stackA, 'E', 'Z');
    ReplaceItem(stackA, 'F', 'Z');
    ReplaceItem(stackA, 'G', 'Z');
    ReplaceItem(stackA, 'H', 'Z');
    ReplaceItem(stackA, 'I', 'Z');
    ReplaceItem(stackA, 'J', 'Z');
    ReplaceItem(stackA, 'K', 'Z');
    ReplaceItem(stackA, 'L', 'Z');

    stackA.Print();

    // Test operator=
    // anotherStack = newStack;
    // anotherStack.Print();
    return 0;
}

// g++ -std=c++17 stackTestLinked.cpp -o stackTestLinked  && ./stackTestLinked