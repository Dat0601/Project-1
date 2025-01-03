#include "searching_algorithm.h"
#include <bits/stdc++.h>
#include "timecounter.h"

vector<int> SearchingAlgorithm::getArray(){
    return array;
}
void SearchingAlgorithm::setArray(vector<int> arr) {
    this->array = array;
}
double SearchingAlgorithm::totalSearchTime(){
    double totalDuration;
    for (TimeCounter timeCounter:timeCounters){
        totalDuration = totalDuration + timeCounter.duration();
    }
    return totalDuration;
}
void SearchingAlgorithm::insertCounter(TimeCounter timeCounter){
    timeCounters.push_back(timeCounter);
}
TimeCounter SearchingAlgorithm::lastTimeCounter(){
    return timeCounters.back();
}
void SearchingAlgorithm::clear(){
    array.clear();
    timeCounters.clear();
}
SearchingAlgorithm::SearchingAlgorithm() {}
SearchingAlgorithm::SearchingAlgorithm(vector<int> array){
    this->array = array;
}
