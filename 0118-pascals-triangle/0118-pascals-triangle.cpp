#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nCr(int n, int r) {
        long long res = 1;
        for (int i = 0; i < r; i++) {
            res = res * (n - i);
            res = static_cast<double>(res) / (i + 1);
        }
        return res;
    }

    void pascalTriangle(int n) {
        for (int c = 1; c <= n; c++) {
            cout << nCr(n - 1, c - 1) << " ";
        }
        cout << "\n";
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int n = 0; n < numRows; n++) {
            vector<int> row;
            for (int c = 0; c <= n; c++) {
                row.push_back(nCr(n, c));
            }
            triangle.push_back(row);
        }
        return triangle;
    }
};


