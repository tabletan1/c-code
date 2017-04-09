//
//  main.cpp
//  MST
//
//  Created by Rencheng Tan on 11/18/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <iterator>

using namespace std;


static int unionNum = 0;

class Connection{
public:
    string node1;
    string node2;
    int cost;
     Connection(string a, string b, int c){
        node1 = a;
        node2 = b;
        cost = c;
    }
};

class Compare1
{
public:
    bool operator()(Connection&a, Connection& b)
    {
        return a.cost > b.cost;
    }
};

class Compare2
{
public:
    bool operator()(Connection&a, Connection& b)
    {
        if(int(a.node1.at(0)) == int(b.node1.at(0)))
            return int(a.node2.at(0)) > int(b.node2.at(0));
        else
            return int(a.node1.at(0)) > int(b.node1.at(0));
    }
};

vector<Connection> getLowCost(vector<Connection> &connections);
bool Union(map<string, int> &m, string a, string b);

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<Connection> connections;
        //下面的图是个苯环，中间加上了几根，如果想验证空表，去掉几根线就行。
        connections.push_back(Connection("A","B",6));
        connections.push_back( Connection("B","C",4));
        connections.push_back( Connection("C","D",5));
        connections.push_back( Connection("D","E",8));
        connections.push_back( Connection("E","F",2));
        connections.push_back( Connection("B","F",10));
        connections.push_back( Connection("E","C",9));
        connections.push_back( Connection("F","C",7));
        connections.push_back( Connection("B","E",3));
        connections.push_back( Connection("A","F",16));
        //这里就输出一下看看结果。
        vector<Connection> res = getLowCost(connections);
        vector<Connection> resl;
        priority_queue<Connection, vector<Connection>, Compare2> pq2;
    for(int i = 0; i< res.size(); i++)
        pq2.push(res[i]);
    while(!pq2.empty())
    {
        Connection temp = pq2.top();
        pq2.pop();
        resl.push_back(temp);
    }
    return 0;
}

vector<Connection> getLowCost(vector<Connection> &connections)
{
    vector<Connection> result;
    if(connections.size() == 0)
        return result;
    map <string, int>  m;
    priority_queue<Connection, vector<Connection>, Compare1> pq;
    for(int i = 0; i < connections.size(); i++)
        pq.push(connections[i]);
    while(!pq.empty())
    {
        Connection temp = pq.top();
        pq.pop();
        string a = temp.node1, b = temp.node2;
        if(Union(m, a, b))
            result.push_back(temp);
    }
    string find = connections[0].node1;
    int t = m[find];
    for(map<string, int> :: iterator i = m.begin(); i != m.end();i++)
    {
        if(i->second != t)
        {
            vector <Connection> a;
            return a;
        }
    }
    return result;
}

bool Union(map<string, int> &m, string a, string b)
{
    if(m.find(a)== m.end() && m.find(b)== m.end())
    {
        m[a] = unionNum;
        m[b] = unionNum;
        unionNum++;
        return true;
    }
    if(m.find(a)!=m.end() && m.find(b) == m.end())
    {
        m[b] = m[a];
        return true;
    }
    if(m.find(a) == m.end() && m.find(b) != m.end())
    {
        m[a] = m[b];
        return true;
    }
    
    if(m.find(a)!= m.end() && m.find(b)!= m.end())
    {
        if(m[a] == m[b])
            return false;
        for(map<string, int> :: iterator i = m.begin(); i != m.end();i++)
        {
            if(i->second == m[a])
                m[(i->first)] = m[b];
        }
        return true;
    }
    return true;
}

    
    
