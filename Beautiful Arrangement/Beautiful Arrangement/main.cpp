//
//  main.cpp
//  Beautiful Arrangement
//
//  Created by Rencheng Tan on 2/25/17.
//  Copyright © 2017 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
void countArrangement(int &result, vector<pair<int, bool> > &nums, vector<int> &tempResult, int N);
int countArrangement(int N);

int main(int argc, const char * argv[]) {
    int b = countArrangement(2);
    cout << b << endl;
}
int countArrangement(int N) {
    if(N == 1)
    return 1;
    int result = 0;
    vector<pair<int, bool> > nums;
    vector<int> tempResult;
    for(int i = 1; i <= N; i++)
        nums.push_back(make_pair(i, false));
    countArrangement(result, nums, tempResult, N);
    return result;
}


void countArrangement(int & result, vector<pair<int, bool> > &nums, vector<int> &tempResult, int N)
{
    if(tempResult.size() == N)
    {
        result++;
        return;
    }
    for(vector<pair<int, bool> >::iterator i = nums.begin(); i != nums.end(); i++)
    {
        if(i->second == false && (i->first % (tempResult.size()+1)
                                  == 0 || (tempResult.size()+1) % i->first == 0))
        {
            tempResult.push_back(i->first);
            i->second = true;
            countArrangement(result, nums, tempResult, N);
            i->second = false;
            tempResult.erase(tempResult.end()-1);
        }
    }
    return;
}
