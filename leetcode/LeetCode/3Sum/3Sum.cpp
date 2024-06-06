// 3 Sum

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <fstream>
#include <algorithm>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);


vector<int> insertionSort(int n, vector<int> arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            int curr = i + 1;
            int prev = i;
            int el = arr[curr];
            while (el < arr[prev] && prev >= 0) {
                arr[curr] = arr[prev];
                --prev;
                --curr;
            }
            arr[curr] = el;
        }
    }
    return arr;
}

void print_line(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

vector<int> removeDuplicates(vector<int>& arr) {
    // Sort the vector to bring duplicates together
    sort(arr.begin(), arr.end());
    
    // Use std::unique to remove duplicates and return the new end iterator
    auto last = unique(arr.begin(), arr.end());
    
    // Erase the duplicates from the vector
    arr.erase(last, arr.end());
    
    return arr;
}

vector<vector<int>> threeSum(vector<int>& nums) {

    //nums = insertionSort(nums.size(), nums);
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    int j, k;

    for (int i = 0; i < nums.size() - 2; i++) {
        if (nums[i] > 0) { 
            break;
        }
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        j = i + 1;
        k = nums.size() - 1;

        while (j < k) { // left pointer smaller than right

            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0) { // move left
                j++;
            }
            else if (sum > 0) { // move right
                k--;
            }
            else {
                vector<int> temp = { nums[i], nums[j], nums[k] };
                result.push_back(temp);
                while (j < k && nums[j] == nums[j + 1]) { // move left pointer if left & left + 1 are same number

                    j++;
                }
                while (j < k && nums[k] == nums[k - 1]) { // move right pointer if right & right - 1 are same number

                    k--;
                }

                j++;
                k--;
            }
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        print_line(result[i]);
    }
    
    return result;
}

int main() {
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

 
    vector<vector<int>> result = threeSum(arr);

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
