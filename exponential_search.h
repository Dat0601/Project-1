#ifndef EXPONENTIAL_SEARCH_H
#define EXPONENTIAL_SEARCH_H

#include <bits/stdc++.h>
#include "sort_needed_search.h"
using namespace std;
class Exponential_Search:public Sort_Needed_Search
{
public:
    string algorithm() override;
    int search(int value) override;
    Exponential_Search();
    Exponential_Search(vector<int> array);
};

#endif // EXPONENTIAL_SEARCH_H
