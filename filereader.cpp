#include "filereader.h"
#include <bits/stdc++.h>
//FileReader::FileReader() {}
using namespace std;
string FileReader::read(string sourceFile){
    ifstream file(sourceFile);
    string res = "";
    if (!file){
        return res;//return empty length if file cannot be opened
    }
    string line;
    while (getline(file,line))
        res = res + line +  " ";
    file.close();
    return res;
}
bool write(string content, string sourceFile){
    ofstream file(sourceFile);
    if (!file) return false;
    file<<content<<endl;
    file.close();
    return true;
}
