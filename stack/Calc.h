#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include "Stack.h"

using namespace std;

class TCalc 
{
public:
    string expr;
    string pstfix;
    TStack<char> st_char;
    TStack<double> st_d;

    int prior(char op);
    TCalc(std::string _expr = "2 + 2");
    TCalc(const TCalc& tc);

    bool CorrectBrackets();
    void ToPostfix();
    string GetPostfix();
    double Calc();
};


inline int TCalc::prior(char k)
{
    switch (k) 
    {
    case '(': return 0;
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    case '^': return 3;
    }
}

TCalc::TCalc(std::string _expr)
{
    expr = _expr;
}

TCalc::TCalc(const TCalc& tc)
{
    expr = tc.expr;
    pstfix = tc.pstfix;
    st_char = tc.st_char;
    st_d = tc.st_d;
}
string TCalc::GetPostfix()
{
    return pstfix;
}
bool TCalc::CorrectBrackets() 
{
    for (int i = 0; i < expr.length(); i++) 
    {
        if (expr[i] == '(')
        {
            st_char.Push(expr[i]);
        }
        else if (expr[i] == ')') 
        {
            if (st_char.IsEmpty()) 
            {
                return false;
            }
            else 
            {
                st_char.Pop();
            }
        }
    }
    return st_char.IsEmpty();
}

void TCalc::ToPostfix()
{
    string infix = "(" + expr + ")";
    pstfix = "";
    st_char.Clear();

    for (int i = 0; i < infix.size(); i++)
    {
        if (isdigit(infix[i]))
        {
            size_t id;
            double tmp = stod(&infix[i], &id);

            ostringstream ss;
            ss << tmp;

            pstfix += ss.str();
            pstfix += " ";

            i += id - 1;
        }
        else if (infix[i] == '(')
        {
            st_char.Push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (st_char.Top() != '(')
            {
                pstfix += st_char.Pop();
                pstfix += " ";
            }
            st_char.Pop();
        }
        else if ((infix[i] == '+') || (infix[i] == '-') || (infix[i] == '/') || (infix[i] == '*') || (infix[i] == '^'))
        {
            while (prior(infix[i]) <= prior(st_char.Top()))
            {
                pstfix += st_char.Pop();
                pstfix += " ";
            }
            st_char.Push(infix[i]);
        }
    }
    if (!pstfix.empty())
        pstfix.pop_back();



}
double TCalc::Calc()
{
    string infix = "(" + expr + ")";
    st_char.Clear();
    st_d.Clear();
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            st_char.Push(infix[i]);
        }
        else if (isdigit(infix[i]))
        {
            size_t id;
            double tmp = stod(&infix[i], &id);
            st_d.Push(tmp);
            i += id - 1;
        }
        else if ((infix[i] == '+') || (infix[i] == '-') || (infix[i] == '/') || (infix[i] == '*') || (infix[i] == '^'))
        {
            while (prior(infix[i]) <= prior(st_char.Top()))
            {
                if (st_d.IsEmpty())
                {
                    throw "err";}
                double second = st_d.Pop();


                if (st_d.IsEmpty())
                {
                    throw "err";
                }
                double first = st_d.Pop();
                char op = st_char.Pop();
                switch (op)
                {
                case '+':
                    st_d.Push(first + second);
                    break;
                case '-':
                    st_d.Push(first - second);
                    break;
                case '*':
                    st_d.Push(first * second);
                    break;
                case '/':
                    st_d.Push(first / second);
                    break;
                case '^':
                    st_d.Push(pow(first, second));
                    break;
                }
            }
            st_char.Push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (st_char.Top() != '(')
            {
                if (st_d.IsEmpty()) 
                    throw "err";

                double second = st_d.Pop();


                if (st_d.IsEmpty()) 
                    throw "err";

                double first = st_d.Pop();

                char op = st_char.Pop();

                switch (op)
                {
                case '+':
                    st_d.Push(first + second);
                    break;
                case '-':
                    st_d.Push(first - second);
                    break;
                case '*':
                    st_d.Push(first * second);
                    break;
                case '/':
                    st_d.Push(first / second);
                    break;
                case '^':
                    st_d.Push(pow(first, second));
                    break;
                }
            }
            st_char.Pop();
        }
    }

    if (st_d.IsEmpty())
    {
        throw "err";
    }
    double result = st_d.Pop();

    if (!(st_d.IsEmpty()))
    { throw "err";}

    return result;
}