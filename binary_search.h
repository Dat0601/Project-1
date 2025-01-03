#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <bits/stdc++.h>
#include "sort_needed_search.h"
using namespace std;
class Binary_Search: public Sort_Needed_Search
{
public:
    string algorithm() override;
    int search(int value) override;
    Binary_Search();
    Binary_Search(vector<int> array);
};

#endif // BINARY_SEARCH_H
