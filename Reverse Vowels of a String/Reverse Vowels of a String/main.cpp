//
//  main.cpp
//  Reverse Vowels of a String
//
//  Created by Rencheng Tan on 5/12/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
string cTos (char a );
string reverseVowels(string s);

int main(int argc, const char * argv[]) {
    // insert code here...
    string a = "A man a plan a canal: Panama";
    string b = reverseVowels(a);
    cout << b << endl;
    return 0;
}

    string cTos (char a )
    {
        stringstream ss;
        string s;
        ss << a;
        ss >> s;
        return s;
    }
    string reverseVowels(string s) {
        int i = 0, j = s.size()-1;
        string vowels = "aeiouAEIOU";
        while(i < j)
        {
            if(s[i] == ' ')
            {
                i++;
                continue;
            }
            if(s[j] == ' ')
            {
                j--;
                continue;
            }
            string chf(cTos(s[i])), chs(cTos(s[j]));
            size_t found = vowels.find(chf);
            if (found == std::string::npos)
            {
                i++;
                continue;
            }
            size_t found2 = vowels.find(chs);
            if (found2 == std::string::npos)
            {   j--;
                continue;
            }
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        return s;
    }
