

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>
#include <time.h>
#include "StackTypeArray.h"

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

int main() { return 0; }