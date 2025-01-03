#ifndef INTERPOLATION_SEARCH_H
#define INTERPOLATION_SEARCH_H

#include <bits/stdc++.h>
#include "sort_needed_search.h"
using namespace std;
class Interpolation_Search: public Sort_Needed_Search
{
public:
    string algorithm() override;
    int search(int value) override;
    Interpolation_Search();
    Interpolation_Search(vector<int> array);
};

#endif // INTERPOLATION_SEARCH_H
