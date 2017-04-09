//
//  main.cpp
//  60p1
//
//  Created by Rencheng Tan on 4/7/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//
#include <iostream>
#include "LongInt.h"

using namespace std;

int main()
{
    LongInt int1, int2, int3;
    
    cout << "Please enter first long integer >> ";
    cin >> int1;
    cout << "Please enter second long integer >> ";
    cin >> int2;
    
    int3 = int1 + int2;
    cout << int3 << endl;
    
    return 0;
}
