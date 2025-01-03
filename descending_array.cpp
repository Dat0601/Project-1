#include "descending_array.h"
#include<bits/stdc++.h>
#include "array_generator.h"
using namespace std;
void Descending_Array::generate(int size){
    array.clear();
    for (int i = size; i >=1; i--) {
        array.push_back(i);
    }
}
