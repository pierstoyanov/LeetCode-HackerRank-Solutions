#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <string>
#include <vector>
#include <functional>


using namespace std;

void insertionSort(int N, int arr[]) {
    int i, j;
    int value;
    for (i = 1;i < N;i++)
    {
        value = arr[i];
        j = i - 1;
        while (j > 0 && value < arr[j])
        {
            arr[j + 1] = arr[j];
            j = j - 1;

        }
        for (int k = 0;k < N;k++)
        {
            printf("%d", arr[k]);
            printf(" ");
        }
        printf("\n");
        arr[j + 1] = value;
    }
    for (j = 0;j < N;j++)
    {
        printf("%d", arr[j]);
        printf(" ");
    }
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

int main(void) {

    ifstream file("data.txt");
    string n_temp;
    getline(file, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(file, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> v_arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        v_arr[i] = arr_item;
    }

    int* arr = v_arr.data();

    insertionSort(n, arr);

    return 0;
}
