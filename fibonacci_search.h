#ifndef FIBONACCI_SEARCH_H
#define FIBONACCI_SEARCH_H

#include<bits/stdc++.h>
#include "sort_needed_search.h"
class Fibonacci_Search:public Sort_Needed_Search
{
public:
    string algorithm() override;
    int search(int value) override;
    Fibonacci_Search();
    Fibonacci_Search(vector<int> array);
};

#endif // FIBONACCI_SEARCH_H
