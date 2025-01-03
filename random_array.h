#ifndef RANDOM_ARRAY_H
#define RANDOM_ARRAY_H

#include "array_generator.h"
class Random_Array:public Array_Generator
{
public:
    virtual void generate(int size) override;
};

#endif // RANDOM_ARRAY_H
