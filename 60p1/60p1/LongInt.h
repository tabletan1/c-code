//
//  LongInt.h
//  60p1
//
//  Created by Rencheng Tan on 4/7/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#ifndef LongInt_h
#define LongInt_h
#include <iostream>
#include "StackLi.h"

using namespace std;

class LongInt
{
    StackLi<int> * longint;
public:
    LongInt();
    ~LongInt();
    friend istream& operator>>(istream &is, LongInt& a);
    friend ostream& operator<<(ostream &os, LongInt& a);
    friend LongInt* operator+(const LongInt& a1, const LongInt& a2);
    void operator=(LongInt* a);
    
};



#endif /* LongInt_h */
