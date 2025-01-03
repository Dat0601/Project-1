#include "random_array.h"
#include<bits/stdc++.h>
#include "array_generator.h"
using namespace std;
void Random_Array::generate(int size){
    array.clear();
    for (int i = 1; i <= size; i++) {
        array.push_back(i);
    }

    random_device random;
    mt19937 generator(random());

    shuffle(array.begin(), array.end(), generator);
}

