#include "linear_search.h"
#include "searching_algorithm.h"
#include "timecounter.h"
#include <bits/stdc++.h>
using namespace std;
string Linear_Search::algorithm(){
    return "Linear Search";
}
int Linear_Search::search(int value){
    TimeCounter timeCounter;
    timeCounter.startSearch();
    int size = (int) array.size();
    for (int i=0;i<size;i++){
        if (array[i]== value){
            timeCounter.endSearch();
            timeCounters.push_back(timeCounter);
            return i;
        }
    }
    timeCounter.endSearch();
    timeCounters.push_back(timeCounter);
    return -1;
}
Linear_Search::Linear_Search():SearchingAlgorithm() {}
Linear_Search::Linear_Search(vector<int> array):SearchingAlgorithm(array) {}
