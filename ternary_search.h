#ifndef TERNARY_SEARCH_H
#define TERNARY_SEARCH_H

#include <bits/stdc++.h>
#include "sort_needed_search.h"
using namespace std;
class Ternary_Search:public Sort_Needed_Search
{
public:
    string algorithm() override;
    int search(int value) override;
    Ternary_Search();
    Ternary_Search(vector<int> array);
};

#endif // TERNARY_SEARCH_H
