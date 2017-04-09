//
//  main.cpp
//  merge array
//
//  Created by Rencheng Tan on 11/21/15.
//  Copyright © 2015 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

int main(int argc, const char * argv[]) {
    vector<int> a = {1,2,3,4};
    vector<int> b = {3,4,5,6};
    merge(b,4,a,4);
    cout << "a" << endl;
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int position[4] = {0,0,0,0};
    if (nums1[m-1] <= nums2[0])
    {
        for(int i = 0; i <= n; i++)
        {
            nums1[m+i] = nums2[i];
        }
    }
    if (nums2[n-1] <= nums1[0])
    {
        for(int i = n; i >= 0; i--)
        {
            nums1.insert(nums1.begin(),nums2[i]);
        }
    }
    else
    {
        if (nums2[0] < nums1[m-1] && nums1[m-1] < nums2[n-1])
        {
            for( ; position[0] <= m-1; position[0] ++)
            {
                if(nums1[position[0]] >= nums2[0])
                    break;
            }
            for( ; position[1] <= n-1; position[1] ++)
            {
                if(nums2[position[1]] >= nums1[m-1])
                    break;
            }
            for (int i = 0; i <= position[1]; i++)
            {
                for(vector<int> :: iterator it = nums1.begin() + position[0]; it != nums1.end(); it++)
                {
                    if(nums2[i] <= *it)
                    {
                        nums1.insert(it, nums2[i]);
                        break;
                    }
                }
            }
            for (int j = position[1]+1; j <= n-1; j++ )
                nums1.push_back(nums2[j]);
        }
        if(nums2[n-1] > nums1[0] && nums2[n-1] < nums1[m-1])
        {
            for( ; position[2] <= n-1; position[2] ++)
            {
                if(nums1[0] <= nums2[position[2]])
                    break;
            }
            for(; position[3] <= m-1; position[3]++)
            {
                if(nums2[n-1] <= nums1[position[3]])
                    break;
            }
            int count = 0;
            for(int i = position[2]; i <= n-1; i++)
            {
                for(vector<int> :: iterator iter = nums1.begin(); iter != nums1.begin() + position[3] + 1 + count; iter ++)
                {
                    if(nums2[i] <= *iter)
                    {
                        nums1.insert(iter, nums2[i]);
                        count ++;
                        break;
                        
                    }
                }
            }
            for(int i = n-position[2] - 1; i >= 0; i--)
                nums1.insert(nums1.begin(),nums2[i]);
        }
    }
}