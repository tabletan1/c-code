//
//  main.cpp
//  Intersection of Two Arrays
//
//  Created by Rencheng Tan on 5/18/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2);

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    vector<int> a = {1};
    vector<int> b = {1};
    vector<int> c = intersection (a,b);
    cout << c[0] << endl;
    return 0;
}
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> num1;
    vector<int> result;
    for(int i = 0; i < nums1.size(); i++)
        num1.insert(nums1[i]);
    for(int j = 0; j < nums2.size(); j++)
    {
        if(num1.find(nums2[j]) != num1.end())
        {
            if( find(result.begin(), result.end(), nums2[j]) == result.end())
                result.push_back(nums2[j]);
        }
    }
    return result;
}