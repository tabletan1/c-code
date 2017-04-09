//
//  main.cpp
//  container duplicate 2
//
//  Created by Rencheng Tan on 11/18/15.
//  Copyright © 2015 Rencheng Tan. All rights reserved.
//


#include <iostream>
#include <vector>
#include <map>

using namespace std;
bool containsDuplicate(vector<int>&, int);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a= {1,2,3,1};
    int f = 2;
    bool k = containsDuplicate(a, f);
    if (k == 1)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}

bool containsDuplicate(vector<int>& nums, int f)
{
    map<int, int> int_map;
    map<int, int>::iterator iter;
    for (int i = 0; i<nums.size(); i++) {
        if((iter=int_map.find(nums[i]) )!= int_map.end() ){
            if (i - iter->second <= f) {
                return true;
            }else{
                int_map.erase(iter);
            }
        }
        int_map.insert(pair<int, int>(nums[i], i));
    }
    return false;
}
