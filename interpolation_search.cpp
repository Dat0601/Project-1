#include "interpolation_search.h"
#include "searching_algorithm.h"
#include "timecounter.h"
#include <bits/stdc++.h>
using namespace std;

string Interpolation_Search::algorithm(){
    return "Interpolation Search";
}
int Interpolation_Search::search(int value){
    TimeCounter timeCounter;
    timeCounter.startSearch();
    int left = 0, right = (int) sortedIndexArray.size() - 1;
    while (left <= right) {
        if (left == right) {
            timeCounter.endSearch();
            timeCounters.push_back(timeCounter);
            if (sortedIndexArray[left].first == value) {
                return sortedIndexArray[left].second;
            }
            else {
                return -1;
            }
        }
        int rightValue = sortedIndexArray[right].first;
        int leftValue = sortedIndexArray[left].first;
        if ((value < leftValue) || (value > rightValue)) {
            break;
        }
        int pos = left + floor(((value - leftValue) * 1.0) / (rightValue - leftValue) * (right - left));

        if (sortedIndexArray[pos].first == value) {
            timeCounter.endSearch();
            timeCounters.push_back(timeCounter);
            return sortedIndexArray[pos].second;
        } else if (sortedIndexArray[pos].first < value) {
            left = pos + 1;
        } else {
            right = pos - 1;
        }
    }
    timeCounter.endSearch();
    timeCounters.push_back(timeCounter);
    return -1;
}

Interpolation_Search::Interpolation_Search():Sort_Needed_Search() {}
Interpolation_Search::Interpolation_Search(vector<int> array):Sort_Needed_Search(array) {}

