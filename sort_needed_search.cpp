#include "sort_needed_search.h"
#include "searching_algorithm.h"
#include <bits/stdc++.h>
using namespace std;

void Sort_Needed_Search::buildSortedIndexArray(){
    int size = (int) array.size();
    for (int i = 0; i < size; i++) {
        sortedIndexArray.push_back({array[i], i});
    }
    if (isAscending(sortedIndexArray)) {
        isSorted = true;
        return;
    }
    sort(sortedIndexArray.begin(), sortedIndexArray.end());
    isSorted = true;
}
void Sort_Needed_Search::clear(){
    sortedIndexArray.clear();
    SearchingAlgorithm::clear();
}
Sort_Needed_Search::Sort_Needed_Search(): SearchingAlgorithm() {
    this ->isSorted = false;
}
Sort_Needed_Search::Sort_Needed_Search(vector<int> array): SearchingAlgorithm(array) {
    this -> isSorted = false;
}
