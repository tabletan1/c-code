//
//  main.cpp
//  Evaluate Division
//
//  Created by Rencheng Tan on 4/4/17.
//  Copyright © 2017 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries);
void helper(string &start, string &end, int &sum, unordered_map<string, unordered_map<string, double> > &graph, vector<double> &result, unordered_map<string, bool> &visited);

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    std::pair <string, string > e1 = make_pair("a", "b");
    std::pair <string, string > e2 = make_pair("bc","cd");
    std::pair <string, string > q1 = make_pair("cd","bc");
    vector<pair<string, string>> equations;
    equations.push_back(e1);
    equations.push_back(e2);
    vector<double>  values = {2.0, 5.0};
    vector<pair<string, string>> queries;
    queries.push_back(q1);
    vector<double> result = calcEquation(equations, values, queries);
    cout << result[0] << endl;
    
    return 0;
}


vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
    vector<double> result;
    unordered_map<string, bool> visited;
    if(equations.size() == 0)
        return result;
    
    unordered_map<string, unordered_map<string, double> > graph;
    for(int i = 0 ; i < equations.size(); i++)
    {
        graph[equations[i].first].insert(make_pair(equations[i].second, values[i]));
        graph[equations[i].second].insert(make_pair(equations[i].first, 1/values[i]));
        visited[equations[i].first] = false;
        visited[equations[i].second] = false;

    }
    for(int i = 0; i < queries.size(); i ++)
    {
        if(visited.find(queries[i].first) == visited.end() ||
           visited.find(queries[i].second) == visited.end())
        {
            result.push_back(-1);
            continue;
        }
        int sum = 1;
        //bool find = false;
        size_t pre_size = result.size();
        visited[queries[i].first] = true;
        helper(queries[i].first, queries[i].second, sum, graph, result, visited);
        visited[queries[i].first] = false;
        if (pre_size == result. size())
            result.push_back(-1);
       /* if(find)
            result.push_back(sum);
        else
            result.push_back(-1);*/
    }
    return result;
}
void helper(string &start, string &end, int &sum, unordered_map<string, unordered_map<string, double> > &graph, vector<double> &result, unordered_map<string, bool> &visited)
{
    //cout << visited[end] << endl;
    if(start == end)
    {
        result.push_back(sum);
        return;
    }
    if(graph[start].size() == 0)
        return;
    
    for(auto it = graph[start].begin(); it != graph[start].end(); ++it)
    {
        if(visited[it->first])
            continue;
        sum *= (it->second);
        string nextStart = (it->first);
        visited[nextStart] = true;
        helper(nextStart, end, sum, graph, result, visited);
        visited[nextStart] = false;
        sum /= (it->second);
        //return;
    }
    
}
