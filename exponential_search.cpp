#include "exponential_search.h"
#include <bits/stdc++.h>
#include "sort_needed_search.h"
#include "timecounter.h"
using namespace std;

string Exponential_Search::algorithm(){
    return "Exponential Search";
}

int Exponential_Search::search(int value){
    TimeCounter timeCounter;
    if (!isSorted){
        buildSortedIndexArray();
    }
    timeCounter.startSearch();
    if (sortedIndexArray[0].first == value) {
        timeCounter.endSearch();
        timeCounters.push_back(timeCounter);
        return sortedIndexArray[0].second;
    }
    int size = (int) sortedIndexArray.size();
    int pos = 1;
    while ((pos < size) && (sortedIndexArray[pos].first <= value)) {
        pos *= 2;
    }
    int left = pos / 2, right = min(pos, size - 1);
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sortedIndexArray[mid].first == value) {
            timeCounter.endSearch();
            timeCounters.push_back(timeCounter);
            return sortedIndexArray[mid].second;
        } else if (sortedIndexArray[mid].first < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    timeCounter.endSearch();
    timeCounters.push_back(timeCounter);
    return -1;
}

Exponential_Search::Exponential_Search():Sort_Needed_Search() {}
Exponential_Search::Exponential_Search(vector<int> array):Sort_Needed_Search(array) {}
