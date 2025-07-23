#include <bits/stdc++.h> // Added header for all standard C++ libraries
using namespace std;

class Solution{
public:
    int findMedian(vector<vector<int>>&matrix) {
        // Time Complexity: O((max-min) * r * c), Space Complexity: O(1)
      int r = matrix.size();
      int c = matrix[0].size();

      int middleCount = (r*c)/2;
      int minElement = INT_MAX;
      int maxElement = INT_MIN;

      for(int i=0;i<r;i++){
        minElement = min(matrix[i][0],minElement);
        maxElement = max(matrix[i][c-1],maxElement);
      }

      for (int k = minElement; k <= maxElement; ++k) {
        int count = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] <= k) count++;
            }
        }
        if (count > (r * c) / 2) return k;
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
    cout << "Median of the matrix is: " << median << endl;
    return 0;
}