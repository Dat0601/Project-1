#include "array_generator.h"
#include <bits/stdc++.h>
using namespace std;
vector<int> Array_Generator::generatedArray() {
    return array;
}

string Array_Generator::generatedArrayString() {
    string res = "";
    int size = (int) array.size();
    for (int i = 0; i < size; i++) {
        res += to_string(array[i]) + " ";
    }
    return res;
}

