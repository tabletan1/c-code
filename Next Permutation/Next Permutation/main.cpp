//
//  main.cpp
//  Next Permutation
//
//  Created by Rencheng Tan on 12/18/15.
//  Copyright © 2015 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void nextPermutation(vector<int>& nums) ;

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a={1,3,2};
    nextPermutation(a);
    cout << a[1] << a[2] << endl;
    return 0;
}
void nextPermutation(vector<int>& nums) {
    int i =nums.size()-1;
    int indicator = 0;
    for(; i >=0; i --)
    {
        if(i -1 >= 0 && nums[i-1]< nums[i])
        {
            int swap2 = i;
            for(int j = i; j <nums.size(); j ++)
            {
                
                if(nums[j] > nums[i-1] && (j+1) < nums.size() && nums[j+1] <= nums[i-1])
                    swap2 = j;
                {
                    iter_swap(nums.begin()+i-1, nums.begin()+swap2);
                    indicator = 1;
                    break;
                }
            }
        }
    }
    if(indicator ==1)
        sort(nums.begin(),nums.end());
    sort(nums.begin()+i, nums.end());
}