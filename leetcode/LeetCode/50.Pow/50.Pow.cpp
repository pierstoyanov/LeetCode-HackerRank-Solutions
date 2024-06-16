// 50.Pow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);
double myPow(double x, int n);



double myPow(double x, int n) {
    // handle negative power
    if (n < 0) {
        x = 1 / x; 
        n = abs(n);
    }
    // handle 0 power
    if (n == 0) {
        return 1;
    }
    // handle x = 1
    if (x == 1) {
        return 1;
    }

    double result = 1;
    while (n > 0) {
        // if n is even, halve the number of operations by using x^2
        if (n % 2 == 0) {
            x = x * x;
            n = n / 2;
        }
        // if n is odd 
        else {
            result = result * x;
            n = n - 1;
        }
    }

    return result;
}


int main() {
    ifstream inputFile("data.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
        return 1;
    }

    double x;
    int y;
    string line;

    // Read a line from the file
    if (getline(inputFile, line)) {
        // Create a stringstream from the line
        stringstream ss(line);

        // Extract the values
        if (!(ss >> x >> y)) {
            std::cerr << "Error reading values from line." << std::endl;
            return 1;
        }
    }
    else {
        std::cerr << "Error reading line from file." << std::endl;
        return 1;
    }

    inputFile.close();

    double res = myPow(x, y);
    cout << res << endl;

    return 0;
}

string ltrim(const string & str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}
