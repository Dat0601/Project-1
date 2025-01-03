#ifndef SEARCH_CONTEXT_H
#define SEARCH_CONTEXT_H

#include "searching_algorithm.h"
class Search_Context
{
private:
    SearchingAlgorithm *search;
public:
    Search_Context();
    void setSearching(SearchingAlgorithm *search);
    SearchingAlgorithm* getSearch();
    string searchValue(int value);
    Search_Context(SearchingAlgorithm *search);
};

#endif // SEARCH_CONTEXT_H
