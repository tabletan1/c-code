//
//  main.cpp
//  plusone
//
//  Created by Rencheng Tan on 11/18/15.
//  Copyright © 2015 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> plusOne(vector<int>&);

int main()
{
    vector<int> a;
    for (int i = 9; i > 8; i --)
    {
        a.push_back(i);
    }
    
    a = plusOne(a);
    for(vector<int> :: iterator it = (a.end()-1); it != a.begin()-1; it --)
      cout << *it << endl;

}
    vector<int> plusOne(vector<int>& digits)
    {
//        
//        for (int i = 0; i < digits.size(); i ++)
//        if (*(digits.end()-1) != 9)
//        {
//            *(digits.end()-1) = *(digits.end()-1) + 1;
//            return digits;
//        }
//        else
//        {
//            vector<int> newVector;
        int k = 0;
        cout <<digits.size()-1<< endl;
        vector<int> :: iterator it = digits.begin();
        signed long n = -1;
//        vector<int> :: size_type i = digits.size() - 1;
//        bool l = (i > n);
//        cout << l << endl;
        
        for(signed long i = digits.size() - 1; i > n; i--)
        {
            //cout << "a" << endl;

            if (*(it + i) == 9)
            {
                k ++;
                *(it + i) = 0;
                //cout << "a" << endl;
            }
            else
                break;
        }
        if (k == digits.size())
        {
            digits.insert(digits.begin(), 1);
        }
        else
            *(it + digits.size() - k - 1) = *(it + digits.size() - k - 1) + 1;
        //cout << *(it - k) << endl;
        return digits;
    }

            


