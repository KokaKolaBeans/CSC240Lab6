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

    StackTypeLinked<ItemType> tempStack;

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

// template <class ItemType>

// bool Identical(const StackTypeLinked<ItemType> &stack1, const StackTypeLinked<ItemType> &stack2)
// {

//     bool identical = true;
//     NodeType<ItemType> *locationStack1 = stack1.topPtr;
//     NodeType<ItemType> *locationStack2 = stack2.topPtr;
//     int counterStack1 = 0;
//     int counterStack2 = 0;

//     while (locationStack1 != nullptr)
//     {

//         locationStack1 = locationStack1->next;
//         counterStack1++;
//     }

//     while (locationStack2 != nullptr)
//     {

//         locationStack2 = locationStack2->next;
//         counterStack2++;
//     }

//     if (counterStack1 == counterStack2) // same size
//     {

//         *locationStack1 = stack1.topPtr;
//         *locationStack2 = stack2.topPtr;

//         for (int k = 0; k < counterStack1; k++)

//         {

//             if (locationStack1->info != locationStack2->info)
//             {

//                 identical = false;
//                 break;
//             }
//             locationStack1 = locationStack1->next;
//             locationStack2 = locationStack2->next;
//         }
//     }
//     else
//     {

//         identical = false;
//     }

//     return identical;
// }

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

    // for (int k = 0; k < 100; k++)
    // {
    //     // stackA.Push(getRandomLetter(true));
    //     // stackA.Push('D');
    // }

    // for (int k = 0; k < 10; k++) // same size; dif letters
    // {
    //     stackA.Push(getRandomLetter(true));
    //     stackB.Push(getRandomLetter(true));
    // }

    // stackB.Push(getRandomLetter(true)); // B add
    // stackB.Push(getRandomLetter(true));
    // stackB.Push(getRandomLetter(true));

    // for (int k = 0; k < 5; k++) // same size; same letter
    // {
    //     char letter = getRandomLetter(true);
    //     stackA.Push(letter);
    //     stackB.Push(letter);
    // }

    stackA.Push('A');
    stackA.Push('B');
    stackA.Push('C');
    stackA.Push('D');
    stackA.Push('E');
    stackA.Push('F');

    stackB.Push('A');
    stackB.Push('B');
    stackB.Push('C');
    stackB.Push('D');
    stackB.Push('E');
    stackB.Push('F');

    // stackB.Push(getRandomLetter(true)); // now B is bigger; random letter selection
    // stackB.Push(getRandomLetter(true));
    // stackB.Push(getRandomLetter(true));

    // stackA.Print();

    // ReplaceItem(stackA, 'A', 'Z');
    // ReplaceItem(stackA, 'B', 'Z');
    // ReplaceItem(stackA, 'C', 'Z');
    // ReplaceItem(stackA, 'D', 'Z');
    // ReplaceItem(stackA, 'E', 'Z');
    // ReplaceItem(stackA, 'F', 'Z');
    // ReplaceItem(stackA, 'G', 'Z');
    // ReplaceItem(stackA, 'H', 'Z');
    // ReplaceItem(stackA, 'I', 'Z');
    // ReplaceItem(stackA, 'J', 'Z');
    // ReplaceItem(stackA, 'K', 'Z');
    // ReplaceItem(stackA, 'L', 'Z');

    // stackA.Print();
    cout << "Stack A: " << endl;
    stackA.Print();
    cout << "Stack B: " << endl;
    stackB.Print();

    cout << endl
         << endl;

    bool testId = Identical(stackA, stackB);
    cout << "stack1 and stack2 Identical: " << testId << endl;
    // Test operator=
    // anotherStack = newStack;
    // anotherStack.Print();
    return 0;
}

// g++ -std=c++17 stackTestLinked.cpp -o stackTestLinked  && ./stackTestLinked