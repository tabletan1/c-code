//
//  main.cpp
//  Decode Ways
//
//  Created by Rencheng Tan on 6/23/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numDecodings(string s);
int main(int argc, const char * argv[]) {
    // insert code here...
    string a("765");
    std::cout << numDecodings(a) << endl;
    return 0;
}
int numDecodings(string s) {
    if(s.empty() || s[0]<'1' || s[0]>'9') return 0;
    vector<int> dp(s.size()+1,0);
    dp[0] = dp[1] = 1;
    
    for(int i=1; i<s.size(); i++) {
        if(!isdigit(s[i])) return 0;
        int v = (s[i-1]-'0')*10 + (s[i]-'0');
        if(v<=26 && v>9) dp[i+1] += dp[i-1];
        if(s[i]!='0') dp[i+1] += dp[i];
        if(dp[i+1]==0) return 0;
    }
    return dp[s.size()];
}