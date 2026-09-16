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

#include "StackType.h"

using namespace std;

int main()
{

    StackType<int> stack;
    // stack.Print();
    stack.Push(4);
    stack.Push(4);
    stack.Push(5);
    stack.Push(4);
    stack.Push(3);
    stack.Push(4);

    stack.Print();

    cout << endl
         << endl;

    stack.ReplaceItem(stack, 4, 10);

    stack.Print();

    StackType<int> stack;
    // stack.Print();
    stack.Push(4);
    stack.Push(4);
    stack.Push(5);
    stack.Push(4);
    stack.Push(3);
    stack.Push(4);

    // stack.ReplaceItem(stack, 4, 10); // replace all occurances of '4' with '10'

    // stack.Print();g++ -std=c++17 stackTest.cpp -o StackProgram && ./StackProgram

    return 0;
}

// g++ -std=c++17 stackTest.cpp -o StackProgram