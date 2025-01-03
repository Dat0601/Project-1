#ifndef JUMP_SEARCH_H
#define JUMP_SEARCH_H

#include <bits/stdc++.h>
#include "sort_needed_search.h"
using namespace std;
class Jump_Search:public Sort_Needed_Search
{
public:
    string algorithm() override;
    int search(int value) override;
    Jump_Search();
    Jump_Search(vector<int> array);
};

#endif // JUMP_SEARCH_H
