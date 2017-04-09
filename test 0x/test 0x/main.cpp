//
//  main.cpp
//  test 0x
//
//  Created by Rencheng Tan on 2/10/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int f = 0xC0;
    bool c = f & 0x80;
    cout <<  c << endl;
    return 0;
}
