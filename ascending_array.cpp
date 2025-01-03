#include "ascending_array.h"
#include<bits/stdc++.h>
#include "array_generator.h"
using namespace std;
void Ascending_Array::generate(int size){
    array.clear();
    for (int i = 1; i <= size; i++) {
        array.push_back(i);
    }
}
