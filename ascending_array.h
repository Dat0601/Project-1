#ifndef ASCENDING_ARRAY_H
#define ASCENDING_ARRAY_H

#include "array_generator.h"
class Ascending_Array:public Array_Generator
{
public:
    virtual void generate(int size) override;
};

#endif // ASCENDING_ARRAY_H
