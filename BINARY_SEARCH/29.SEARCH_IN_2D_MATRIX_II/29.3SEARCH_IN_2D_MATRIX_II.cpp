#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        //  optimal solution
        // time complexity: O(r+c)
        // space complexity: O(1)

        int c = matrix[0].size();
        int r = matrix.size();

        int i = 0;
        int j = c - 1;

        while (i < r && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }

        return false;
    }
};

int main() {
    int r, c;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;
    vector<vector<int>> matrix(r, vector<int>(c));
    cout << "Enter matrix elements row-wise:\n";
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> matrix[i][j];
        }
    }
    int target;
    cout << "Enter target: ";
    cin >> target;
    Solution sol;
    bool found = sol.searchMatrix(matrix, target);
    if (found) {
        cout << "Target found in matrix." << endl;
    } else {
        cout << "Target not found in matrix." << endl;
    }
    return 0;
}
