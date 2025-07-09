#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &matrix)
    {
        // BETTER FORCE APPROACH
        // Time Complexity O(R * log C)
        // Space Complexity O(1)

        int rowWithMaxOnes = -1;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int upperBoundIdx = cols;

        for (int row = 0; row < rows; row++)
        {
            int index = upper_bound(matrix[row].begin(), matrix[row].end(), 0) - matrix[row].begin();

            if (index < upperBoundIdx)
            {
                rowWithMaxOnes = row;
                upperBoundIdx = index;
            }
        }

        return rowWithMaxOnes;
    }
};

int main()
{
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter matrix elements (0s and 1s only, row-wise sorted):\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    Solution sol;
    int result = sol.rowWithMax1s(matrix);

    if (result != -1)
        cout << "Row with maximum 1s: " << result << endl;
    else
        cout << "No 1s found in the matrix.\n";

    return 0;
}
