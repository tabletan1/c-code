//
//  main.cpp
//  Search for a Range
//
//  Created by Rencheng Tan on 12/14/15.
//  Copyright © 2015 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int>& nums, int start, int end, int target);
vector<int> searchRange(vector<int>& nums, int target);


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {1,5}, b;
    b = searchRange(a, 4);
    std::cout << b[0] << b[1] << endl;
    return 0;
}
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> result;
    if(nums.size()==0 || target < nums[0] || target > nums[(nums.size()-1)])
    {
        result = {-1, -1};
        return result;
    }
    if(nums[0]== nums[(nums.size()-1)])
    {
        if (target == nums[0])
        {
            result = {0,int(nums.size()-1)};
            return result;
        }
        else
        {
            result = {-1, -1};
            return result;
        }
    }
    int start = 0, end = int(nums.size()-1);
    int target_loc = binary_search(nums, start, end, target);
    int range_s = 0, range_e = 0;
    if (target_loc == -1)
    {
        result = {-1, -1};
        return result;
    }
    else
    {
        for(range_s = target_loc; nums[range_s] == nums[target_loc] && range_s >= 0; range_s --);
        range_s++;
        for(range_e = target_loc; nums[range_e] == nums[target_loc] && range_e <= end; range_e ++);
        range_e--;
        result = {range_s, range_e};
        return result;
    }
}

    int binary_search(vector<int>& nums, int start, int end, int target)
    {
        if (start > end)
            return -1;
        int mid = (start+end)/2;
        if(target > nums[mid])
            return binary_search(nums, mid+1, end, target);
        if(target < nums[mid])
            return binary_search(nums, start, mid-1, target);
        else
            return mid;
    }