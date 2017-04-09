//
//  main.cpp
//  Count Primes
//
//  Created by Rencheng Tan on 4/12/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
int countPrimes(int n);

int main(int argc, const char * argv[]) {
    // insert code here...
    int i = countPrimes(50);
    return 0;
}
int countPrimes(int n) {
    
    std::vector<bool> num(n - 1, true);
    num[0] = false;
    int res = 0, limit = sqrt(n);
    for (int i = 2; i <= limit; ++i) {
        if (num[i - 1]) {
            for (int j = i * i; j < n; j += i) {
                num[j - 1] = false;
            }
        }
    }
    for (int j = 0; j < n - 1; ++j) {
        if (num[j]) ++res;
    }
    return res;
}