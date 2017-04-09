//
//  main.cpp
//  Verify Preorder Serialization of a Binary Tree
//
//  Created by Rencheng Tan on 2/19/17.
//  Copyright © 2017 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
bool isValidSerialization(string preorder);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}


bool isValidSerialization(string preorder) {
    
    if (preorder.empty())
        return false;
    
    istringstream in(preorder);
    vector<string> v;
    string val;
    int d = 0;
    
    while(getline(in, val, ','));
      //  v.push_back(val);
    
    for (int i = 0; i < v.size() - 1; ++i) {
        if (v[i] == "#") {
            if (d == 0)
                return false;
            else
                --d;
        }
        else
            ++d;
    }
    return d != 0 ? false : v.back() == "#";
}
