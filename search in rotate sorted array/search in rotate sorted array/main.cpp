//
//  main.cpp
//  search in rotate sorted array
//
//  Created by Rencheng Tan on 12/14/15.
//  Copyright © 2015 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
bool search(vector<int>& nums, int target);
bool binary_search(vector<int>& nums, int start, int end, int target);


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a;
    a = {1,2,1};
    bool b = search(a,2);
    std::cout << b << endl;
    return 0;
}

bool search(vector<int>& nums, int target) {
    vector<int> :: iterator it;
    int start = 0, end = (nums.size()-1);
    if (nums[0] == nums[end])
    {
        if (nums[0] == target)
            return 1;
        else return 0;
    }
    it = max_element(nums.begin(),nums.end());
    int len = (it - nums.begin());
    if(target > *it)
        return false;
    else
        if (it == (nums.end()-1))
            return binary_search(nums, start, end, target);
    if (target > nums[end])
        return binary_search(nums, start, len, target);
    if (target < nums[end])
        return binary_search(nums, (len + 1), end, target);
    else
        return 1;
}
bool binary_search(vector<int>& nums, int start, int end, int target)
{
    int mid = (start+end)/2;
    if (start > end)
        return false;
    if (target < nums[mid])
        return binary_search(nums, start, (mid-1), target);
    if (target > nums[mid])
        return binary_search(nums, (mid+1), end, target);
    else
        return true;
}
