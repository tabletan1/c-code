//
//  main.cpp
//  Set Matrix Zeroes
//
//  Created by Rencheng Tan on 12/8/15.
//  Copyright © 2015 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void setZeroes(vector<vector<int>>& matrix);

int main(int argc, const char * argv[])
{
    // insert code here...
    vector<vector<int>> a = {{0,1}};
    setZeroes(a);
    cout << "a" << endl;
    return 0;
}
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if(row == 0) return;
        int col = matrix[0].size();
        if(col == 0) return;
        vector<int> colZero(col,0), rowZero(row,0);
        for(int i = 0; i < row ; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(matrix[i][j] == 0)
                {
                    rowZero[i]=1;
                    colZero[j]=1;
                }
            }
        }
        for(int i = 0; i < row; i++)
        {
            if(rowZero[i]=1)
            {
                for(int j = 0; j < col; j ++)
                {
                    matrix[i][j] == 0;
                }
            }
        }
        for(int j = 0; j < col; j++)
        {
            if(colZero[j]=1)
            {
                for(int i = 0; i < row; i ++)
                {
                    matrix[i][j] == 0;
                }
            }
        }
    }