#include "jump_search.h"
#include <bits/stdc++.h>
#include "timecounter.h"
#include "sort_needed_search.h"
using namespace std;

string Jump_Search::algorithm(){
    return "Jump Search";
}

int Jump_Search::search(int value){
    TimeCounter timeCounter;
    if (!isSorted){
        buildSortedIndexArray();
    }
    timeCounter.startSearch();
    int step = (int) floor(sqrt((int) array.size()));
    if (step < 1) {
        step = 1;
    }
    int prev = 0, size = (int) array.size();
    while (sortedIndexArray[prev].first < value) {
        prev += step;
        if (prev >= size) {
            break;
        }
    }
    prev -= step;

    int lower = max(0, prev), upper = min(size, prev + step);
    for (int i = lower; i <= upper; i++) {
        if (sortedIndexArray[i].first == value) {
            timeCounter.endSearch();
            timeCounters.push_back(timeCounter);
            return sortedIndexArray[i].second;
        }
    }
    timeCounter.endSearch();
    timeCounters.push_back(timeCounter);
    return -1;
}

Jump_Search::Jump_Search():Sort_Needed_Search() {}
Jump_Search::Jump_Search(vector<int> array):Sort_Needed_Search(array) {}
