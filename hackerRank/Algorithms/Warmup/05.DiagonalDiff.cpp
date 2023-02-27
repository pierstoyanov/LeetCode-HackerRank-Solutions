#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std ;

int diagonalDifference(vector<vector<int>> arr) {
    int diag = 0, revDiag = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        diag += arr[i][i];
        revDiag += arr[i][arr.size() - i - 1];
    }

    return abs(diag - revDiag);
}

// int main()
// {
//     int n;
//     cin >> n;
//     vector<vector<int>> arr(n);
//     for (size_t i = 0; i < n; i++)
//     {
//         vector<int> line;

//         std::string input;
//         getline(std::cin, input);
//         std::istringstream iss(input);
//         int number;
//         while (iss >> number)
//         {
//             line.push_back(number);
//         }
//         arr.push_back(line);
//     }

//     for (int i = 0; i < n; i++)
//     {
//         auto vec = arr[i];
//         std::string str(vec.begin(), vec.end());
//         cout << str << endl;
//     }
    
// }