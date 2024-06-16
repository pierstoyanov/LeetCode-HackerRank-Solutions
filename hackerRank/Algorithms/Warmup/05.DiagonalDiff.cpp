#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
    int diag = 0, revDiag = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        diag += arr[i][i];
        revDiag += arr[i][arr.size() - i - 1];
    }

    return abs(diag - revDiag);
}

int main()
{
    vector<vector<int>> arr;
    int n;
    cin >> n;
 
    for (int i = 0; i < n; i++)
    {
        vector<int> line;

        string input;
        getline(cin, input);
        
        istringstream iss(input);
        int number;
        while (iss >> number)
        {
            line.push_back(number);
        }
        arr.push_back(line);
    }

    for (int i = 0; i < n; i++)
    {
        auto vec = arr[i];
        string str(vec.begin(), vec.end());
        cout << str << endl;
    }   
}