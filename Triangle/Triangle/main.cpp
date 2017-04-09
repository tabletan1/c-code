//
//  main.cpp
//  Triangle
//
//  Created by Rencheng Tan on 1/2/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int minimumTotal(vector<vector<int>>& triangle);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> a =  {{2},{3,4},{6,5,7}, {4,1,8,3}};
    int b =minimumTotal(a);
    cout << b << endl;
    return 0;
}
int minimumTotal(vector<vector<int>>& triangle) {
    vector <int> min={};
    int end = triangle.size()-1;
    for(int i = 0; i < triangle.size(); i ++)
    {
        triangle[i+1][0] += triangle[i][0];
        triangle[i+1][triangle[i+1].size()-1] += triangle[i][triangle[i].size()-1];
        for(int j = 1; j < triangle[i+1].size()-1; j++)
        {
            int a = triangle[i][j-1];
            int b = triangle[i][j];
            int temp = 0;
            if(a > b)
                temp = b;
            else temp = a;
            triangle[i+1][j] = triangle[i+1][j] + temp;
        }
    }
    for(int i = 0; i < triangle[end].size() ; i ++)
    {
        min.push_back(triangle[end][i]);
    }
    vector <int> :: iterator it  = min_element(min.begin(), min.end());
    return *it;
    
}
