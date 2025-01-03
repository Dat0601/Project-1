#ifndef SORT_NEEDED_SEARCH_H
#define SORT_NEEDED_SEARCH_H

#include <bits/stdc++.h>
#include "searching_algorithm.h"
class Sort_Needed_Search:public SearchingAlgorithm
{
protected:
    bool isSorted;
    vector<pair<int, int>> sortedIndexArray;
public:
    Sort_Needed_Search();
    template<typename T> bool isAscending(const vector<T> &arr) {
        //Kiểm tra tăng
        for (int i = 0; i < (int) arr.size() - 1; i++) {
            if (arr[i] > arr[i+1]) {
                return false;
            }
        }
        return true;
    }
    void buildSortedIndexArray();
    void clear() override;
    Sort_Needed_Search(vector<int> arr);
};

#endif // SORT_NEEDED_SEARCH_H
