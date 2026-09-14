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
  // Test with integer stack
  cout << "========== Testing Integer Stack ==========" << endl;
  try{
    StackType<int> stack;
    stack.Print();
    stack.Push(4);
    stack.Push(4);
    stack.Push(5);
    stack.Push(4);
    stack.Push(3);
    stack.Push(4);
    stack.Print();
    cout << "The iterator over the stack items:\n";
    // Now try a range-based loop over a StackType;
    // automatically uses the StackTypeIterator and the operator*
    for(auto i : stack){
      cout << i << endl;  // i is now the actual item value
    }

  }
  catch ( const FullStack& e )
  {
    cout << "Stack is full!" << endl;
  }
  catch(const EmptyStack& e){
    cout << "Stack is empty!" << endl;
  }

  // Test with double stack
  cout << "\n========== Testing Double Stack ==========" << endl;
  try{
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
  catch ( const FullStack& e )
  {
    cout << "Stack is full!" << endl;
  }
  catch(const EmptyStack& e){
    cout << "Stack is empty!" << endl;
  }

  // Test with string stack
  cout << "\n========== Testing String Stack ==========" << endl;
  try{
    StackType<string> stringStack(10);
    stringStack.Push("Hello");
    stringStack.Push("World");
    stringStack.Push("C++");
    stringStack.Push("Templates");
    stringStack.Print();
    cout << "Iterating with range-based for:" << endl;
    for(auto str : stringStack){
      cout << "  " << str << endl;
    }
  }
  catch ( const FullStack& e )
  {
    cout << "Stack is full!" << endl;
  }
  catch(const EmptyStack& e){
    cout << "Stack is empty!" << endl;
  }

  // Range-based for loop for an array of integers.
  cout << "\n========== Testing Array Iterator ==========" << endl;
  cout << "The iterator over the array items:\n";
  int numbers[] = {4, 5, 6, 7 ,8, 9};
  for(auto num : numbers){
    cout << num << endl;
  }

  // Test with vector
  cout << "\n========== Testing Vector ==========" << endl;
  std::vector<int> myvector;
  for (int i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  for(auto num : myvector){
    std::cout << ' ' << num;
  }
  std::cout << '\n';

  return 0;
}
