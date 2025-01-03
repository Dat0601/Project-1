#ifndef FILEREADER_H
#define FILEREADER_H

#include<bits/stdc++.h>
using namespace std;
class FileReader
{
public:
    static string read(string sourceFile);
    static bool write(string content, string sourceFile);
};

#endif // FILEREADER_H
