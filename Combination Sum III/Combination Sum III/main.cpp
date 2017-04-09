//
//  main.cpp
//  Combination Sum III
//
//  Created by Rencheng Tan on 12/21/15.
//  Copyright © 2015 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void find_comb(int start, int count, int sol_num, vector<int>& sol, vector<vector<int>>& all_sol, vector<int> candidates, int target);
vector<vector<int>> combinationSum3(int k, int n);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> a;
    a = combinationSum3(2,6);
    cout << a[0][0] << endl;
    return 0;
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> candidates;
    for(int i = 1; i <= 9; i++)
    {
        candidates.push_back(i);
    }
    vector<vector<int>> all_sol;
    vector<int> sol;
    //sort(candidates.begin(), candidates.end());
    int sol_num = 0;
    if((k+1)*k/2 > n)
        return all_sol;
    else
    {
        find_comb(0, k, sol_num, sol, all_sol, candidates, n);
        return all_sol;
    }
}
void find_comb(int start, int count, int sol_num, vector<int>& sol, vector<vector<int>>& all_sol, vector<int> candidates, int target)
{
    if(target == 0 && count == sol_num)
    {
        all_sol.push_back(sol);
        return;
    }
    for(int i = start; i < candidates.size(); i++)
    {
        if(i > start && candidates[i]==candidates[i-1]) continue;
        if(target >= candidates[i] && sol_num < count)
        {
            sol.push_back(candidates[i]);
            sol_num++;
            find_comb(i+1, count, sol_num, sol, all_sol, candidates, target-candidates[i]);
            sol.pop_back();
            sol_num--;
        }
    }
    return;
}