//
//  main.cpp
//  Find the Difference
//
//  Created by Rencheng Tan on 11/1/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <map>

using namespace std;

char findTheDifference(string s, string t);


int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "a";
    string t = "aa";
    char c = findTheDifference(s,t);
    cout <<  c << endl;
}
char findTheDifference(string s, string t)
{
    map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        if (mp.find(s[i]) != mp.end())
            mp[s[i]]++;
        else
            mp.insert(make_pair(s[i], 1));
    }
    for (int i = 0; i < t.length(); i++)
    {
        if (mp.find(t[i]) != mp.end())
            mp[t[i]]--;
        else
            mp.insert(make_pair(t[i], 1));
    }
    map<char, int>::iterator it = mp.begin();
    while (it != mp.end())
    {
        if ((*it).second == -1 || (*it).second == 1)
            return (*it).first;
        it++;
    }
    return (*it).first;
}
