//
//  main.cpp
//  Add Binary
//
//  Created by Rencheng Tan on 4/13/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string addBinary(string a, string b);

int main(int argc, const char * argv[]) {
    // insert code here...
    string a = "100";
    string b = "110010";
    string result = addBinary(a,b);
    cout << result << endl;
}
string addBinary(string a, string b) {
    if(a.empty())
        return b;
    if(b.empty())
        return a;
    string result;
    string :: iterator i = a.end()-1;
    string :: iterator j = b.end()-1;
    int cout = 0;
    while(i != a.begin()-1 && j != b.begin()-1)
    {
        switch (*i+*j+cout)
        {
            case 48*2:
                cout = 0;
                result = "0" + result;
                i--; j--;
                break;
            case 48+49:
                cout = 0;
                result = "1" + result;
                i--; j--;
                break;
            case 49*2:
                cout = 1;
                result = "0" + result;
                i--; j--;
                break;
            case 49+50:
                cout = 1;
                result = "1" + result;
                i--; j--;
                break;
        }
    }
    while(i != a.begin()-1)
    {
        if(cout != 0)
        {
            switch (*i+cout)
            {
                case 49:
                    cout = 0;
                    result = "1" + result;
                    i--;
                    break;
                case 50:
                    cout = 1;
                    result = "0" + result;
                    i--;
                    break;
            }
        }
        else
        {result = *i + result;
            i--;}
    }
    while(j != b.begin()-1)
    {
        if(cout != 0)
        {
            switch (*j+cout)
            {
                case 49:
                    cout = 0;
                    result = "1" + result;
                    j--;
                    break;
                case 50:
                    cout = 1;
                    result = "0" + result;
                    j--;
                    break;
            }
        }
        else
        {result = *j + result;
            j--;}
    }
    while(cout != 0)
    {
        stringstream ss;
        ss<<cout;
        string s1 = ss.str();
        result = s1 + result;
        cout = 0;
    }
    return result;
}