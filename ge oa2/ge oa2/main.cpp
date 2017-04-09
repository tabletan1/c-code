//
//  main.cpp
//  ge oa2
//
//  Created by Rencheng Tan on 12/18/16.
//  Copyright © 2016 Rencheng Tan. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> lines =
    {"(11/01/2015-04:00:00) :: START",
    "(11/01/2015-04:00:00) :: CONNECTED",
    "(11/01/2015-04:30:00) :: DISCONNECTED",
    "(11/01/2015-04:45:00) :: CONNECTED",
    "(11/01/2015-05:00:00) :: SHUTDOWN"};
    
    tm  a[lines.size()];
    double c_t = 0;
    double t_t = 0;
    tm *t_start, *t_connected, *t_disconnected, *t_shutdown;
    time_t tm_start = 0, tm_connected = 0, tm_disconnected, tm_shutdown;
    for(int i = 0; i < lines.size(); i++)
    {
        a[i].tm_mon = stoi(lines[i].substr(1,2));
        cout << a[i].tm_mon << endl;
        a[i].tm_mday = stoi(lines[i].substr(4,2));
        cout << a[i].tm_mday << endl;
        a[i].tm_year = stoi(lines[i].substr(7,4));
        cout << a[i].tm_year << endl;
        a[i].tm_hour = stoi(lines[i].substr(12,2));
        cout << lines[i].substr(12,2) << endl;
        a[i].tm_min = stoi(lines[i].substr(15,2));
        cout << a[i].tm_min << endl;
        a[i].tm_sec = stoi(lines[i].substr(18,2));
        cout << a[i].tm_sec << endl;
        string temp = lines[i].substr(25);
        tm temptm = a[i];
        if(temp == "START")
        {
            t_start = &temptm;
            tm_start = timegm(t_start);
        }
        if(temp == "CONNECTED")
        {
            t_connected = &temptm;
            tm_connected = timegm(t_connected);
        }
        if(temp == "DISCONNECTED")
        {
            t_disconnected  = &temptm;
            tm_disconnected = timegm(t_disconnected);
            c_t += abs(difftime(tm_connected, tm_disconnected));
        }
        if(temp == "SHUTDOWN")
        {
            //setenv("TZ", "", 0);
            //tzset();
            //cout << temptm.tm_hour << temptm.tm_min << temptm.tm_sec << endl;
            t_shutdown = &temptm;
            t_shutdown->tm_isdst = 0;
            tm_shutdown = timegm(t_shutdown);
            t_t += abs(difftime(tm_start, tm_shutdown));
            c_t += abs(difftime(tm_connected, tm_shutdown));
        }
        
    }
    double percent = c_t/t_t;
    cout << percent << endl;
    
    
    /*a[0].tm_hour = 10;
    a[0].tm_sec = 50;
    time_t m = mktime(&a[0]);
    std::cout << m << endl;
    return 0;*/
}
