//
//  main.cpp
//  Word Ladder
//
//  Created by Rencheng Tan on 3/6/17.
//  Copyright © 2017 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;



bool oneWordDif(string & s1, string & s2);
int ladderLength(string beginWord, string endWord, vector<string>& wordList);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

bool oneWordDif(string & s1, string & s2)
{
    if(s1.size()!= s2.size())
        return false;
    int count = 0;
    for(int i = 0; i < s1.size(); i++)
    {
        if(s1[i] == s2[i])
            continue;
        count ++;
    }
    if(count == 1)
        return true;
    return false;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_map<string, bool> visited;
    for(int i = 0 ; i < wordList.size(); i ++)
        visited[wordList[i]] = false;
    
    vector<string> temp1, temp2;
    temp1.push_back(beginWord);
    while(!temp1.empty())
    {
        for(int j = 0; j < temp1.size(); j++)
        {
            for(int i = 0 ; i < wordList.size(); i ++)
            {
                if(temp1[j] == endWord)
                    return true;
                
                if(oneWordDif(wordList[i],temp1[j]) && !visited[wordList[i]])
                   {
                       visited[wordList[i]] = true;
                       temp2.push_back(wordList[i]);
                   }
                   }
                   }
                   temp1 = temp2;
                   temp2.clear();
                   }
                   return false;
}
