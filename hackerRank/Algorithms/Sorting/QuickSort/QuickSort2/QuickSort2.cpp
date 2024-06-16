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

vector<int> quickSort(vector<int> arr) {
    vector<int> left, right, equal;
    int p = arr[0];

    equal.push_back(p);
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == p) {
            equal.push_back(arr[i]);
        }
        else if (arr[i] < p) {
            left.push_back(arr[i]);
        }
        else if (arr[i] > p) {
            right.push_back(arr[i]);
        }
    }

    left.insert(left.end(), equal.begin(), equal.end());
    left.insert(left.end(), right.begin(), right.end());


    print_line(left);

    return left;
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

    quickSort(arr);

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