//
//  main.cpp
//  Concatenated Words
//
//  Created by Rencheng Tan on 1/4/17.
//  Copyright © 2017 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
//#include <>
using namespace std;

struct Compare
{
    bool operator()(string &a, string & b)
    {
        return a.length() <= b.length();
    }
};

bool canForm(string & word, set<string> &dic)
{
    if(dic.empty())
        return false;
    vector<bool> dp(word.size()+1, false);
    dp[0] = true;
    //int j = 0;
    for(int i = 1; i < word.size(); i++)
    {
        /*while(j < i)
        {
            string str = word.substr(j, i-j+1);
            if(dic.find(str) != dic.end())
            {
                j = ++i;
                dp[i] = true;
            }
            break;
        }*/
        
        for(int j = 0; j < i; j++)
        {
            if(!dp[j])
                continue;
            string str = word.substr(j, i-j+1);
            if(dp[j] && dic.find(str) != dic.end())
            {
                dp[i+1] = true;
                //j = i;
                break;
            }
        }
    }
    return dp[word.size()];
}

vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    vector<string> result;
    if(words.size() == 0 || words.size() == 1)
        return result;
    sort(words.begin(), words.end(), Compare());
    //for( int i = 0; i < words.size(); i ++)
      //  cout << words[i] << endl;
    set<string> dic;
    for(int i = 0; i < words.size(); i++)
    {
        if(canForm(words[i], dic))
            result.push_back(words[i]);
        else
            dic.insert(words[i]);
    }
    return result;
}



int main()
{
    vector<string> a = {"cat","dog","catdog"};
    vector<string> words =findAllConcatenatedWordsInADict(a);
    for( int i = 0; i < words.size(); i ++)
        cout << words[i] << endl;
    
    
    
};
