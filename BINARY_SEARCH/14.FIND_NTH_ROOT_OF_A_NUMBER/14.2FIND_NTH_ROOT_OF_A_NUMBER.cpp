#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int NthRoot(int N, int M)
    {
        // Time Complexity: O(M * N)
        // Space Complexity: O(1)
        for (int i = 1; i <= M; i++)
        {
            int val = 1;
            for (int j = 1; j <= N; j++)
            {
                val = val * i;
            }

            if (val == M)
                return i;
            else if (val > M)
                break;
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    int N, M;
    cout << "Enter N and M: ";
    cin >> N >> M;
    int result = sol.NthRoot(N, M);
    cout << "Nth root: " << result << endl;
    return 0;
}
