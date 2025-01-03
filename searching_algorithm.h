#ifndef SEARCHING_ALGORITHM_H
#define SEARCHING_ALGORITHM_H

#include<bits/stdc++.h>
#include "timecounter.h"
using namespace std;
class SearchingAlgorithm
{
protected:
    vector <int> array;
    vector <TimeCounter> timeCounters;
public:
    SearchingAlgorithm();
    vector <int> getArray();
    virtual void setArray(vector <int> array);
    double totalSearchTime();
    void insertCounter(TimeCounter timeCounter);
    TimeCounter lastTimeCounter();
    virtual void clear();
    virtual string algorithm()=0;
    virtual int search(int value)=0;
    SearchingAlgorithm(vector<int> array);
};

#endif // SEARCHING_ALGORITHM_H
