#ifndef ARRAY_GENERATOR_H
#define ARRAY_GENERATOR_H

#include<bits/stdc++.h>
using namespace std;
class Array_Generator
{
protected:
    vector<int> array;
public:
    virtual void generate(int size) = 0;
    virtual vector<int> generatedArray();
    virtual string generatedArrayString();
};

#endif // ARRAY_GENERATOR_H
