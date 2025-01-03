#include "binary_search.h"
#include <bits/stdc++.h>
#include "sort_needed_search.h"
#include "timecounter.h"
using namespace std;
string Binary_Search::algorithm(){
    return "Binary Search";
}
int Binary_Search::search(int value){
    TimeCounter timeCounter;
    if (!isSorted){
        buildSortedIndexArray();
    }
    timeCounter.startSearch();
    int left = 0, right = (int) sortedIndexArray.size() - 1;
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
Binary_Search::Binary_Search():Sort_Needed_Search() {}
Binary_Search::Binary_Search(vector<int> array):Sort_Needed_Search(array) {}
