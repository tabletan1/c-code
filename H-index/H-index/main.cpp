//
//  main.cpp
//  H-index
//
//  Created by Rencheng Tan on 4/28/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int hIndex(vector<int>& citations);
int main(int argc, const char * argv[]) {
   
    vector<int> a = {0};
    int c = hIndex(a);
    cout << c << endl;
    return 0;
}
int hIndex(vector<int>& citations) {
    if(citations.size()==0)
        return 0;
    sort(citations.begin(), citations.end(), greater<int>());
    //vector<int> :: iterator i = citations.begin();
    for(int i = 1; i <= citations.size(); i++)
    {
        if(i > citations[i-1])
            return i-1;
    }
    return int(citations.size());
    //return 0;
}