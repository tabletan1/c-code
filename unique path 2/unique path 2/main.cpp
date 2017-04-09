//
//  main.cpp
//  unique path 2
//
//  Created by Rencheng Tan on 11/23/15.
//  Copyright © 2015 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> a (1,vector<int>(0));
    int i = uniquePathsWithObstacles(a);
    cout << i << endl;
    return 0;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> path(m ,vector<int>(n));
    for(int i=0 ; i < m; i ++)
    {
        if (obstacleGrid[i][0] == 0)
        {
            for(int j = i; j < m; j++)
                path[j][0]= 0;
            break;
        }
        else
            path[i][0]=1;
    }
    for(int i=0 ; i < n; i ++)
    {
        if (obstacleGrid[0][i] == 0)
        {
            for(int j = i; j < n; j++)
                path[0][j]= 0;
            break;
        }
        else
            path[0][i]=1;
    }
    for(int i = 1; i < m ; i++ )
        for (int j = 1 ; j < n ; j++)
        {
            if(obstacleGrid[i][j]== 1)
                path[i][j]= 0;
            else
                path[i][j]= path[i-1][j]+path[i][j-1];
        }
    return path[m-1][n-1];
}