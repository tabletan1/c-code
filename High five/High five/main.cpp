//
//  main.cpp
//  High five
//
//  Created by Rencheng Tan on 11/18/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;



class Result{
public:
    int id;
    int value;
    Result(int id, int value){
        this->id = id;
        this->value = value;
    }
};

class Compare
{
public:
    bool operator() (Result& R1, Result& R2)
    {
        return R1.value > R2.value;
    }
};

map<int, double> & getHighFive(vector<Result> & res);

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
        Result r1 = Result(1, 95);
        Result r2 = Result(1, 95);
        Result r3 = Result(1, 91);
        Result r4 = Result(1, 91);
        Result r5 = Result(1, 93);
        Result r6 = Result(1, 105);
        
        Result r7 =  Result(2, 6);
        Result r8 =  Result(2, 6);
        Result r9 =  Result(2, 7);
        Result r10 =  Result(2, 6);
        Result r11 =  Result(2, 6);
        vector<Result> res = {r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11};
        map<int, double> result = getHighFive(res);
    
    return 0;
}

map<int, double> & getHighFive(vector<Result> & res)
{
    map<int, double> result;
    map<int, vector<int> > m;
    vector<int> temp;
    
    //priority_queue<Result, std::vector<Result>, Compare> pq;
    
    for(int i = 0; i < res.size(); i++)
    {
        //cout << res[i].id << endl;
        //cout << res[i].value << endl;
        if(m.find(res[i].id) != m.end())
            (m[res[i].id]).push_back(res[i].value);
         else
         {
             m[res[i].id] = temp;
             m[res[i].id].push_back(res[i].value);
         }
    }
    map<int, vector<int> > :: iterator i;
    for(i = m.begin(); i!= m.end();i++)
    {
        double sum = 0;
        priority_queue<int> pq;
        vector<int> tp;
        tp = (*i).second;
        for(int k = 0; k < tp.size();k++)
            pq.push(tp[k]);
        
        for(int j = 0; j < 5; j++)
        {
            sum += pq.top();
            pq.pop();
        }
        sum /= 5;
        result[(*i).first] = sum;
    }
    
    map<int, double>  :: iterator k = result.begin();
    cout << (*k).second << endl;
    k++;
    cout <<(*k).second << endl;
    return result;
}


