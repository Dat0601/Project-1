#include "search_context.h"
#include<bits/stdc++.h>
#include "searching_algorithm.h"
using namespace std;
void Search_Context::setSearching(SearchingAlgorithm *search){
    this->search = search;
}
string Search_Context::searchValue(int value){
    string log = "***";
    log = log + "Searching "+ to_string(value)+":";
    int position = search->search(value);
    if (position != -1){
        log = log + " found at " + to_string(position);
    } else{
        log = log + " not found";
    }
    ostringstream searchResult;
    double duration = search->lastTimeCounter().duration();
    searchResult<<fixed<<setprecision(3)<<duration;
    log = log + ", duration = " + searchResult.str()+" ms.\n";
}
SearchingAlgorithm* Search_Context::getSearch(){
    return search;
}
Search_Context::Search_Context() {}
Search_Context::Search_Context(SearchingAlgorithm *search){
    this->search = search;
}
