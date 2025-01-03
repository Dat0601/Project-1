#ifndef FIELDREADER_H
#define FIELDREADER_H

#include <bits/stdc++.h>
using namespace std;

class FieldReader {
    protected:
        vector<int> inputArray;
        virtual vector<string> split(const string &str, char delimeter);
        virtual string clean(const string &str);
    public:
        virtual bool read(string data);
        virtual vector<int> getInputArray();
};


#endif // FIELDREADER_H
