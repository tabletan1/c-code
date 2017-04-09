//
//  main.cpp
//  3sum
//
//  Created by Rencheng Tan on 12/8/15.
//  Copyright © 2015 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void threeSum(vector<int>& nums);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {-1,0,1,2,-1,-4};
    threeSum(a);
    return 0;
}
void threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        //if(nums.size()<3)
            //return result;
        sort(nums.begin(),nums.end());
        for(unsigned int i=0; i< nums.size(); i++)
        {
            if(i > 0 && nums[i]==nums[i-1])
                continue;
            int p = i+1, j = 0;
            int q = int(nums.size()-1);
            while(p != q && p < q)
            {
                if((nums[i]+nums[p]+nums[q])== 0)
                {
                    vector<int> b;
                    b.push_back(nums[i]);
                    b.push_back(nums[p]);
                    b.push_back(nums[q]);
                    result.push_back(b);
                    sort(result[j].begin(),result[j].end());
                    j++;
                    p++;
                    while(p< q && nums[p]==nums[p-1])
                    {
                        p++;
                    }
                    q--;
                    while(p<q && nums[q]==nums[q+1])
                    {
                        q--;
                    }
                }
                if((nums[i]+nums[p]+nums[q])> 0)
                    q--;
                if((nums[i]+nums[p]+nums[q])< 0)
                    p++;
            }
            cout << p << endl;
        }
        //return result;
    
    
    }