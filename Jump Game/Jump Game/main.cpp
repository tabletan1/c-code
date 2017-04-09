//
//  main.cpp
//  Jump Game
//
//  Created by Rencheng Tan on 1/4/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool canJump(vector<int>& nums);
bool find(vector<int>& nums,int begInd,int length);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a ={1,1,2,2,0,1,1};
    bool b = canJump(a);
    cout << b << endl;
    return 0;
}
bool canJump(vector<int>& nums) {
    if(nums.size()==0 ||nums.size()==1)
        return true;
    return find(nums, 0, nums.size()-1);
}
bool find(vector<int>& nums,int begInd,int length)
{
    int i = begInd+nums[begInd];
    if(i >= length)
        return true;
    if(nums[begInd] == 0)
        return false;
    for(int j = begInd +1 ; j < i ; j++)
    {
        if(nums[j] > nums[begInd]-j+begInd)
            return find(nums, j, nums.size()-1);
    }
    return find(nums, i, length);
}