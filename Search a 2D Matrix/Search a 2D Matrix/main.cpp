//
//  main.cpp
//  Search a 2D Matrix
//
//  Created by Rencheng Tan on 12/15/15.
//  Copyright © 2015 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target);
int binary_searchRow(vector<int>& row_first, int start, int end, int target);
bool binary_search(vector<int>& nums, int start, int end, int target);


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> matrix{{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    bool a = searchMatrix(matrix, 24);
    cout << a << endl;
    return 0;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int start = 0, end = matrix.size()-1;
    int start1 = 0, end1 = matrix[0].size()-1;
    if (matrix.size()==0)
        return 0;
    if (matrix.size()==1)
        return binary_search(matrix[0], start1, end1, target);
    vector<int> row_first;
    for(int i = 0; i < matrix.size(); i++)
    {
        row_first.push_back(matrix[i][0]);
    }
    int row = binary_searchRow(row_first, start, end, target);
    bool result = binary_search(matrix[row], start1, end1, target);
    return result;
}






int binary_searchRow(vector<int>& row_first, int start, int end, int target)
{
    int mid = (start+end)/2;
    if(target < row_first[mid])
    {
        if(target > row_first[mid-1])
            return mid-1;
        else
            return binary_searchRow(row_first, start, mid-1, target);
    }
    if(target > row_first[mid])
    {
        if(target < row_first[mid+1])
            return mid;
        else
            return binary_searchRow(row_first, mid+1, end, target);
    }
    else
        return mid;
}
bool binary_search(vector<int>& nums, int start, int end, int target)
{
    if(start > end)
        return 0;
    int mid = (start+end)/2;
    if(target < nums[mid])
        return binary_search(nums, start, mid-1, target);
    if(target > nums[mid])
        return binary_search(nums, mid+1, end, target);
    else
        return 1;
}