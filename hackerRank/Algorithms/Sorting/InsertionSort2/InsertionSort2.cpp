// InsertionSort2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <fstream>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

void print_line(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void insertionSort2(int n, vector<int> arr) {
    for (int i = 0; i < arr.size()-1; i++) {
        if (arr[i] > arr[i + 1]) {
            int curr = i+1;
            int prev = i;
            int el = arr[curr];
            while (el < arr[prev] && prev >= 0) {
                arr[curr] = arr[prev];
                --prev;
                --curr;
            }
            arr[curr] = el;
        }
        print_line(arr);
    }
}

int main()
{
    ifstream file("data.txt");
    string n_temp;
    getline(file, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(file, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    insertionSort2(n, arr);

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
