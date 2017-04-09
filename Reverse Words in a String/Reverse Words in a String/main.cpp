//
//  main.cpp
//  Reverse Words in a String
//
//  Created by Rencheng Tan on 6/23/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;
void reverseWords(string &s);

int main(int argc, const char * argv[]) {
    // insert code here...
    string a("   a   b ");
    reverseWords(a);
    return 0;
}
void reverseWords(string &s) {
    while(s[0] == ' ')
        s.erase(s.begin());
    while(s[s.size()-1] == ' ')
        s.erase(s.end()-1);
    
    for(int i = 0; i < s.size(); i++)
    {
        if(i+1 < s.size() && s[i]==' ' && s[i+1] == ' ')
        {
            s.erase(s.begin()+i);
            i--;
            continue;
        }
    }
    
    
    for(int i = 0 ; i < s.size()/2; i++)
        swap(s[i], s[s.size()-1-i]);
    int l = 0, lable = 0;
    s += " ";
    for(int j = 0 ; j < s.size(); j++)
    {
        
        if(s[j] == ' ')
        {
            lable = j;
            while(l != j &&  l < j)
            {
                swap(s[l], s[j-1]);
                l++;
                j--;
            }
            l = lable+1;
            lable = l;
            j=l-1;
        }
    }
    s.erase(s.end()-1);
    if(s == " ")
        s = "";
    

cout << s << endl;
}