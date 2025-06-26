#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long findNthRoot(int mid, int N, int M)
    {
        long val = 1;
        for (int i = 0; i < N; i++)
        {
            val = val * mid;
            if (val > M)
                break;
        }

        return val;
    }
    int NthRoot(int N, int M)
    {

        /*
            Time Complexity: O(N * log M)
            - log M iterations for binary search, each calling findNthRoot (O(N) loop).

            Space Complexity: O(1)
            - Only constant extra space is used.
        */
        int low = 1;
        int high = M;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            long val = findNthRoot(mid, N, M);

            if (val == M)
            {
                return mid;
            }
            else if (val > M)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    int N, M;
    cout << "Enter N (root) and M (number): ";
    cin >> N >> M;
    int result = sol.NthRoot(N, M);
    if (result == -1)
        cout << "No integer Nth root exists for " << M << endl;
    else
        cout << "The " << N << "th root of " << M << " is " << result << endl;
    return 0;
}

/*
Time Complexity: O(N * log M)
- log M iterations for binary search, each calling findNthRoot (O(N) loop).

Space Complexity: O(1)
- Only constant extra space is used.
*/