#include "ternary_search.h"
#include <bits/stdc++.h>
#include "sort_needed_search.h"
#include "timecounter.h"
using namespace std;

string Ternary_Search::algorithm(){
    return "Ternary Search";
}

int Ternary_Search::search(int value){
    TimeCounter timeCounter;
    if (!isSorted){
        buildSortedIndexArray();
    }
    timeCounter.startSearch();
    int left = 0, right = (int) sortedIndexArray.size() - 1;
    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        if (sortedIndexArray[mid1].first == value) {
            timeCounter.endSearch();
            timeCounters.push_back(timeCounter);
            return sortedIndexArray[mid1].second;
        }
        if (sortedIndexArray[mid2].first == value) {
            timeCounter.endSearch();
            timeCounters.push_back(timeCounter);
            return sortedIndexArray[mid2].second;
        }
        if (value < sortedIndexArray[mid1].first) {
            right = mid1 - 1;
        } else if (value > sortedIndexArray[mid2].first) {
            left = mid2 + 1;
        } else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    timeCounter.endSearch();
    timeCounters.push_back(timeCounter);
    return -1;
}
Ternary_Search::Ternary_Search():Sort_Needed_Search() {}
Ternary_Search::Ternary_Search(vector<int> array):Sort_Needed_Search(array) {}
