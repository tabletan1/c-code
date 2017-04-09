//
//  main.cpp
//  oa Navisens
//
//  Created by Rencheng Tan on 4/2/17.
//  Copyright © 2017 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
long f(int n);

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << f(8181) << endl;
    return 0;
}

long f(int n)
{
    vector<long> dp (n+1, 0);
    dp[1] = 1;
    for(int i = 2; i < dp.size(); i++)
        dp[i] = dp[i-1]+dp[i-2];
    return dp[n];
}

vector<vector<int>
