//
//  LongInt.cpp
//  60p1
//
//  Created by Rencheng Tan on 4/7/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include "LongInt.h"
#include "StackLi.h"

using namespace std;

LongInt::LongInt()
{
    longint = new StackLi<int>();
}
LongInt::~LongInt()
{
}

istream& operator>>(istream &is, LongInt& a)
{
    char c;
    is.get(c);
    while (c != '\n')
    {
        if(isdigit(c))
            a.longint->push(atoi(&c));
        is.get(c);
    }
    return is;
}

ostream& operator<<(ostream &os, LongInt& a)
{
    while(!a.longint->isEmpty())
        os << a.longint->topAndPop();
    return os;
}
LongInt* operator+(const LongInt& a1, const LongInt& a2)
{
    int c = 0, sum = 0;
    LongInt *result = new LongInt();
    while(!a1.longint->isEmpty() && !a2.longint->isEmpty())
    {
        int a = a1.longint->topAndPop();
        int b = a2.longint->topAndPop();
        sum = a + b + c;
        c = sum/10;
	sum = sum%10;
        result->longint->push(sum);
        sum = 0;
    }
    while(!a1.longint->isEmpty())
    {
        int sum = 0;
        while(c != 0)
        {
            int a = a1.longint->topAndPop();
            sum = c + a;
            c = sum/10;
	    sum = sum%10;
            result->longint->push(sum);
	}
        int a = a1.longint->topAndPop();
        result->longint->push(a);
    }
    while(!a2.longint->isEmpty())
    {
        int sum = 0;
        while(c != 0)
        {
            int a = a2.longint->topAndPop();
            sum = c + a;
            c = sum/10;
	    sum = sum%10;
	    result->longint->push(sum);
        }

        int b = a2.longint->topAndPop();
        result->longint->push(b);
    }
    if(c != 0)
        result->longint->push(c);
    return result;
}

void LongInt::operator=(LongInt* a)
{
    this->longint = new StackLi<int>(*(a->longint));
}













