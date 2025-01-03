#include "timecounter.h"
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
void TimeCounter::startSearch(){
    TimeCounter::searchTime.first = high_resolution_clock::now();
}
void TimeCounter::endSearch(){
    TimeCounter::searchTime.second = high_resolution_clock::now();
}
double TimeCounter::duration(){
    system_clock::time_point start = TimeCounter::searchTime.first;
    system_clock::time_point end = TimeCounter::searchTime.second;
    long long duration = duration_cast<microseconds>(end-start).count();
    return duration*1.0/1000;
}
TimeCounter::TimeCounter() {}
