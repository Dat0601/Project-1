#include "fibonacci_search.h"
#include <bits/stdc++.h>
#include "sort_needed_search.h"
#include "timecounter.h"
using namespace std;
string Fibonacci_Search::algorithm(){
    return "Binary Search";
}
int Fibonacci_Search::search(int value){
    TimeCounter timeCounter;
    if (!isSorted){
        buildSortedIndexArray();
    }
    int size = (int) sortedIndexArray.size();
    //Fibo
    int fib2 = 0; //m-2 th
    int fib1 = 1; //m-1 th
    int fib0 = fib1 + fib2; //m
    while (fib0 < size) {
        fib2 = fib1;
        fib1 = fib0;
        fib0 = fib1 + fib2;
    }
    for (int i = size; i <= fib0; i++) {
        sortedIndexArray.push_back({INT_MAX, i});
    }
    timeCounter.startSearch();
    int idx = fib1 - 1; fib0 = fib1; fib1 = fib2; fib2 = fib0 - fib1;
    while (true) {
        if (sortedIndexArray[idx].first == value) {
            timeCounter.endSearch();
            timeCounters.push_back(timeCounter);
            return sortedIndexArray[idx].second;
        } else if (sortedIndexArray[idx].first < value) {
            if (fib1 == 1) break;
            idx += fib2;
            fib0 = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib0 - fib1;
        } else {
            if (fib2 == 0) break;
            idx -= fib2;
            fib0 = fib1;
            fib1 = fib2;
            fib2 = fib0 - fib1;
        }
    }
    if (sortedIndexArray[idx].first == value) {
        timeCounter.endSearch();
        timeCounters.push_back(timeCounter);
        return sortedIndexArray[idx].second;
    }
    timeCounter.endSearch();
    timeCounters.push_back(timeCounter);
    return -1;
}
Fibonacci_Search::Fibonacci_Search():Sort_Needed_Search() {}
Fibonacci_Search::Fibonacci_Search(vector<int> array):Sort_Needed_Search(array) {}

