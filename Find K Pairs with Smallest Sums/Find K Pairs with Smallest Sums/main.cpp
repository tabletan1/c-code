    //
//  main.cpp
//  Find K Pairs with Smallest Sums
//
//  Created by Rencheng Tan on 1/30/17.
//  Copyright © 2017 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k);

struct Compare
{
    bool operator()(pair<int, int> &a,pair<int, int> &b)
    {
        return (a.first+a.second) > (b.first+b.second);
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a = {-999,-999,-996,-993,-991,-982,-981,-972,-972,-969,-965};
    vector<int> b = {-1000,-997,-997,-984,-982,-970,-969,-964,-960,-958,-954,-953};
    vector<pair<int, int>> result  = kSmallestPairs(a,b, 10);
    std::cout << "Hello, World!\n";
    return 0;
}

    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> result;
        if(nums1.size() == 0 || nums2.size() == 0)
            return result;
        if(nums1.size()*nums2.size() <= k)
        {
            for(int i = 0; i < nums1.size(); i ++)
            {
                for(int j = 0 ; j < nums2.size(); j++)
                {
                    pair<int, int> temp = make_pair(nums1[i], nums2[j]);
                    result.push_back(temp);
                }
            }
            return result;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        //int i = 0, min = (nums1.size() > k) ?  nums1.size() : k;
        //int min = nums1.size();
        for(int i = 0; i < nums1.size(); i ++)
        {
            pair<int, int> temp = make_pair(nums1[i], nums2[0]);
            pq.push(temp);
        }
        while(result.size() < k && !pq.empty())
        {
            pair<int, int> temp = pq.top();
            pq.pop();
            result.push_back(temp);
            
            vector<int>::iterator it;
            it = find(nums2.begin(), nums2.end(), temp.second);
            if(it + 1 < nums2.end())
            {
                pair<int, int> newPair = make_pair(temp.first, *(it+1));
                pq.push(newPair);
            }
        }
        return result;
    }
