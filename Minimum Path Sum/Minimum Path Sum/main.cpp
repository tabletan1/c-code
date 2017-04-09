//
//  main.cpp
//  Minimum Path Sum
//
//  Created by Rencheng Tan on 12/23/15.
//  Copyright © 2015 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int minPathSum(vector<vector<int>>& grid);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> a = {{1,3,1},{1,5,1},{4,2,1}};
    int b = minPathSum(a);
    cout << b << endl;
    return 0;
}
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    if(m == 0 || n == 0)
        return 0;
    if(m == 1 && n == 1)
        return grid[m-1][n-1];
    vector<vector<int>> sol(m, vector<int>(n));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++ )
        {
            if(i == 0 && j == 0)
                sol[i][j] = grid[i][j];
            if(i == 0 && j != 0)
                sol[i][j] = sol[i][j-1]+grid[i][j];
            if(j == 0 && i != 0)
                sol[i][j] = sol[i-1][j]+grid[i][j];
            else
                sol[i][j] = min(sol[i-1][j], sol[i][j-1])+grid[i][j];
        }
    }
    return sol[m-1][n-1];
}