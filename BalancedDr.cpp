#include "StackType.h"
#include "math.h"
#include <iostream>
bool IsOpen(char symbol);
bool IsClosed(char symbol);
bool Matches(char symbol, char openSymbol);

int main()
{
  using namespace std;
  char symbol;
  StackType stack;
  StackType expressionStack;
  bool balanced = true;
  char openSymbol;
  string expression = "4 5 6 2 ^ - +";
  
  /*cout << "Enter an expression and press return." << endl;
  cin.get(symbol); 
  expression += symbol;

  while (symbol != '\n' && balanced)
  {
    if (IsOpen(symbol))
      stack.Push(symbol);

    else if (IsClosed(symbol))
    {
      if (stack.IsEmpty())
        balanced = false;
      else
      {
        openSymbol = stack.Top();
        stack.Pop();
        balanced = Matches(symbol, openSymbol);
      }
    }
    cin.get(symbol);
    expression += symbol;
  }
  if (balanced && stack.IsEmpty())
    cout << "Expression is well formed." << endl;
  else
    cout << "Expression is not well formed."  << endl;
  */

  cout << expression << endl;

  //Now evaluate the arithmetic expression.
  //Build the stack.
  int result;
  int op1, op2;
  string operand = "";
  for(char c : expression){
	  if(c != '\n'){
		  if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
			  //operator: pop operand, pop operand, push result
			  op1 = std::stoi(expressionStack.Top(), nullptr, 10);
			  expressionStack.Pop();
			  op2 = std::stoi(expressionStack.Top(), nullptr, 10);
			  expressionStack.Pop();
			  switch(c){
						case '+':
							result = op2 + op1;
							expressionStack.Push(std::to_string(result));
							break;
						case '-':
							result = op2 - op1;
							expressionStack.Push(std::to_string(result));
							break;
						case '*':
							result = op2 * op1;
							expressionStack.Push(std::to_string(result));
							break;
						case '/':
							result = op2 / op1;
							expressionStack.Push(std::to_string(result));
							break;
						case '^':
							result = pow(op2, op1);
							expressionStack.Push(std::to_string(result));
							break;
						default:
							break;
			  }
		  }
		  else if(c != ' '){
			  //build operand
			  operand += c;
		  }
		  else{ //This was a space character
			  //store the operand if it isn't empty.
			  //it is empty if we have found an operator before.
			  if(operand != ""){
				  expressionStack.Push(operand);
			  }
			  operand = "";
		  }
	  }
  }
  expressionStack.Print();
  return 0;
}
    
bool IsOpen(char symbol)
{
  if ((symbol == '(') || (symbol == '{') || (symbol == '['))
    return true;
  else
    return false;
}      

bool IsClosed(char symbol)
{
  if ((symbol == ')') || (symbol == '}') || (symbol == ']'))
    return true;
  else
    return false;
}      

bool Matches(char symbol, char openSymbol)
{
  return  (((openSymbol == '(') && symbol == ')')
        || ((openSymbol == '{') && symbol == '}')
        || ((openSymbol == '[') && symbol == ']'));
}
