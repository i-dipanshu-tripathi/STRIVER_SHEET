#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &mat)
    {
        //  Time Complexity: O(n * m), where n is the number of rows and m is the number of columns.
        //  Space Complexity: O(1), as only a constant amount of extra space is used.

        int n = mat.size();
        int m = mat[0].size();
        int rowIdx = -1;
        int maxOnes = -1;

        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < m; j++)
            {
                cnt += mat[i][j];
            }
            if (cnt > 0 and cnt > maxOnes)
            {
                maxOnes = cnt;
                rowIdx = i;
            }
        }

        return rowIdx;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> mat[i][j];

    Solution sol;
    int result = sol.rowWithMax1s(mat);
    cout << "Row with maximum number of 1s: " << result << endl;
    return 0;
}
