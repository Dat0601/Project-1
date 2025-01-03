#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <bits/stdc++.h>
#include "searching_algorithm.h"
using namespace std;

class Linear_Search:public SearchingAlgorithm
{
public:
    Linear_Search();
    string algorithm() override;
    int search(int value) override;
    Linear_Search(vector<int> array);
};

#endif // LINEAR_SEARCH_H
