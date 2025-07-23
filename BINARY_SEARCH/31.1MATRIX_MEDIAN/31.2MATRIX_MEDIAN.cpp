#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool isPossible(const vector<vector<int>>& matrix, int val) {
        // Time Complexity: O((max-min) * r * log c), Space Complexity: O(1)
        int count = 0;
        for (const auto& row : matrix) {
            count += upper_bound(row.begin(), row.end(), val) - row.begin();
        }
        int total = matrix.size() * matrix[0].size();
        return count >= (total + 1) / 2; // position of median
    }

    int findMedian(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        int minElement = INT_MAX;
        int maxElement = INT_MIN;

        for (int i = 0; i < r; ++i) {
            minElement = min(minElement, matrix[i][0]);
            maxElement = max(maxElement, matrix[i][c - 1]);
        }

        for (int val = minElement; val <= maxElement; ++val) {
            if (isPossible(matrix, val)) {
                return val;
            }
        }

        return -1; 
    }
};



int main() {
    int r, c;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;
    vector<vector<int>> matrix(r, vector<int>(c));
    cout << "Enter matrix elements:\n";
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cin >> matrix[i][j];
        }
    }
    Solution sol;
    int median = sol.findMedian(matrix);
    cout << "Median of matrix: " << median << endl;
    return 0;
}
