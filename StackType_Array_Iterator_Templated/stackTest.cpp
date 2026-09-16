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

    stack.ReplaceItem(stack, 4, 10);

    // stack.Print();

    StackType<int> stackA;
    StackType<int> stackB;

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int k = 0; k < 4; k++)
    {
        int n = rand() % 101;
        stackA.Push(n);
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

    bool id;

    id = Identical(stackA, stackB);

    cout << "Stack A and Stack B Identical: " << id << endl;

    // stack2.ReplaceItem(stack2, -5, 5);

    // stack.Push(4);
    // stack.Push(4);
    // stack.Push(5);
    // stack.Push(4);
    // stack.Push(3);
    // stack.Push(4);

    // stack.ReplaceItem(stack, 4, 10); // replace all occurances of '4' with '10'

    // stack.Print();g++ -std=c++17 stackTest.cpp -o StackProgram && ./StackProgram

    return 0;
}

// g++ -std=c++17 stackTest.cpp -o StackProgram