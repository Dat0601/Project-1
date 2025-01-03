#ifndef TIMECOUNTER_H
#define TIMECOUNTER_H

#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
class TimeCounter
{
protected:
    pair <system_clock::time_point, system_clock::time_point> searchTime;
public:
    TimeCounter();
    void startSearch();
    void endSearch();
    double duration();
};

#endif // TIMECOUNTER_H
