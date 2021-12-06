#include <iostream>
#include <string>
#include "Stack.h"
#include "Calc.h"

void main() 
{
	string expr;
	cout << "Enter expression: ";
	getline(cin, expr);
	TCalc calculator(expr);
	calculator.ToPostfix();

	cout << calculator.GetPostfix() << endl;;
	
	cout << "Result: ";
	
	cout << calculator.Calc() << endl;
}