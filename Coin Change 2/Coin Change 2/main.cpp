//
//  main.cpp
//  Coin Change 2
//
//  Created by Rencheng Tan on 3/6/17.
//  Copyright © 2017 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;



int change(int amount, vector<int>& coins);




int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    vector<int> coins = {1,2,5};
    int a = change(8, coins);
    cout << a << endl;
    
    
    return 0;
}



    int change(int amount, vector<int>& coins) {
        //int result = 0;
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        sort(coins.begin(), coins.end());
        for(int i=0; i<coins.size(); i++){
            for(int j=coins[i]; j<=amount; j++){
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
