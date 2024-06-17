// 22.Generate Parenthesis.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <fstream>
#include <algorithm>
#include <stack>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

void buildTree(int open, int close, string& str, vector<string>& result) {
    // exit recursion

    if (open == 0 && close == 0) {
        result.push_back(str);
    }

    if (open > close || open < 0 || close < 0) {
        return;
    }

    str.push_back('(');
    buildTree(open - 1, close, str, result);
    str.pop_back();

    str.push_back(')');
    buildTree(open, close - 1, str, result);
    str.pop_back();
}    

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string temp;

    buildTree(n, n, temp, result);

    return result;
}

int main() {
    ifstream file("data.txt");
    string n_temp;
    getline(file, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> result = generateParenthesis(n);

    file.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}