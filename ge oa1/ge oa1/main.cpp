//
//  main.cpp
//  ge oa1
//
//  Created by Rencheng Tan on 12/16/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>


using namespace std;
void printAllPaths(int s, int d, map<char, vector<char> > &g,  vector<string> &lines,vector<string> &result);
void helper(char s, char d, map<char, vector<char> > &g, vector<string> &result, map <char, bool> &visited, string &temp);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> lines;
    map<char, vector<char> > g;
    lines = {"A J",
        "A : B C",
        "B : C E G",
        "C : A F",
        "D : C J",
        "F : B H",
        "G : C D",
        "H : A B F I",
        "I : B"};
    char s = lines[0].at(0);
    char d = lines[0].at(2);
    
    for(int i = 1; i < lines.size(); i++)
    {
        //char temp = lines[i].at(0);
        vector<char> t;
        for(int j = 1; j < lines[i].size(); j++)
        {
            if(65 <= int(lines[i][j]) && int(lines[i][j] < 91))
                t.push_back(lines[i][j]);
        }
        g[lines[i].at(0)] = t;
    }
    
    vector<string> result;
    
    printAllPaths(s, d, g, lines, result);
    for(int i = 0; i < result.size();i++)
        cout << result[i] << endl;
    
    
    return 0;
}
void printAllPaths(int s, int d, map<char, vector<char> > &g, vector<string> &lines, vector<string>& result)
{
    
    map <char, bool> visited;
    for (int i = 1; i <= g.size(); i++)
        visited[lines[i].at(0)] = false;
    string temp;
    //vector<string> result;
    
    /*visited[int(s)-65] = true;
    temp += s;
    if(s == d)
        result.push_back(temp);
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        for (int i = 0; i < g[int(s)-65].size(); ++i)
            if (!visited[g[int(s)-65][i]])
                printAllPaths(g[int(s)-65][i], d, g, result, visited, temp);
    }
    temp.erase(temp.end()-1);
    visited[int(s)-65] = false;*/
    helper( s,  d, g, result, visited, temp);
    //return result;
    return;
}

void helper(char s, char d, map<char, vector<char> > &g, vector<string> &result,   map <char, bool> &visited, string &temp)
{
    //cout <<int(s)-65 << endl;
    visited[s] = true;
    temp += s;
    if(s == d)
        result.push_back(temp);
        else // If current vertex is not destination
        {
            // Recur for all the vertices adjacent to current vertex
            for (int i = 0; i < g[s].size(); ++i)
            {
                cout << !visited[g[s][i]] << endl;
                cout << g[s][i] << endl;
                if (!visited[g[s][i]])
                    helper(g[s][i], d, g, result, visited, temp);
            }
        }
    temp.erase(temp.end()-1);
    visited[s] = false;
}
