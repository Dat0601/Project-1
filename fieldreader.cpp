#include "fieldreader.h"
#include <bits/stdc++.h>
using namespace std;
vector<string> FieldReader::split(const string &str, char delimeter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimeter)) {
        tokens.push_back(token);
    }
    return tokens;
}

string FieldReader::clean(const string &str) {
    istringstream iss(str);
    string token;
    string result;

    while (iss >> token) {
        if (!result.empty()) {
            result += " ";
        }
        result += token;
    }
    size_t firstChar = result.find_first_not_of(' ');
    size_t lastChar = result.find_last_not_of(' ');
    return result.substr(firstChar, (lastChar - firstChar + 1));
}

bool FieldReader::read(string data) {
    inputArray.clear();
    int num;
    data = clean(data);
    vector<string> splited = split(data, ' ');
    for (string str: splited) {
        try {
            num = stoi(str);
            inputArray.push_back(num);
        } catch (const invalid_argument &e) {
            return false;
        } catch (const out_of_range &e) {
            return false;
        }
    }
    return true;
}

vector<int> FieldReader::getInputArray() {
    return inputArray;
}

