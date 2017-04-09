//
//  main.cpp
//  nqueens
//
//  Created by Rencheng Tan on 3/9/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//
#define THREAD_NUM		96


#include <iostream>
#include<stdio.h>

using namespace std;
long long solve_nqueen(int n);

int main(int argc, const char * argv[]) {
    long long m = solve_nqueen(8);
    cout << m << endl;
    return 0;
}



long long solve_nqueen(int n)
{
    int bunk = 0;
    unsigned int mask[32];
    unsigned int l_mask[32];
    unsigned int r_mask[32];
    unsigned int m[32];
    
    if(n <= 0 || n > 32) {
        return 0;
    }
    
    const unsigned int t_mask = (1 << n) - 1;
    long long total = 0;
    long long upper_total = 0;
    int i = 0, j;
    unsigned int index;
    
    mask[0] = 0;
    l_mask[0] = 0;
    r_mask[0] = 0;
    m[0] = 0;
    
    for(j = 0; j < (n + 1) / 2; j++) {
        index = (1 << j);
        m[0] |= index;
        
        mask[1] = index;
        l_mask[1] = index << 1;
        r_mask[1] = index >> 1;
        m[1] = (mask[1] | l_mask[1] | r_mask[1]);
        i = 1;
        
        if(n % 2 == 1 && j == (n + 1) / 2 - 1) {
            upper_total = total;
            total = 0;
        }
        
        while(i > 0) {
            if((m[i] & t_mask) == t_mask) {
                i--;
            }
            else {
                index = ((m[i] + 1) ^ m[i]) & ~m[i];
                m[i] |= index;
                if((index & t_mask) != 0) {
                    if(i + 1 == n) {
                        total++;
                        i--;
                    }
                    else {
                        mask[i + 1] = mask[i] | index;
                        l_mask[i + 1] = (l_mask[i] | index) << 1;
                        r_mask[i + 1] = (r_mask[i] | index) >> 1;
                        m[i + 1] = (mask[i + 1] | l_mask[i + 1] | r_mask[i + 1]);
                        i++;
                    }
                }
                else {
                    i --;
                }
            }
        }
    }
    
    bunk = 2;
    
    if(n % 2 == 0) {
        return total * 2;
    }
    else {
        return upper_total * 2 + total;
    }
}