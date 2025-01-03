#ifndef DESCENDING_ARRAY_H
#define DESCENDING_ARRAY_H

#include "array_generator.h"
class Descending_Array:public Array_Generator
{
public:
    virtual void generate(int size) override;
};

#endif // DESCENDING_ARRAY_H
