#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int k, vector<int> &arr, long long curr_time)
    {
        int paintersRequired = 1;
        long long boardPaintedAreaTime = 0;

        for (int len : arr)
        {
            if (boardPaintedAreaTime + len <= curr_time)
            {
                boardPaintedAreaTime += len;
            }
            else
            {
                paintersRequired++;
                boardPaintedAreaTime = len;
            }
        }

        return paintersRequired <= k;
    }

    int paint(int k, int time, vector<int> &arr)
    {
        // Time Complexity: O(N * log(max_time-min_time))
        // Space Complexity : O(1) extra(excluding input array)
        long long min_time = *max_element(arr.begin(), arr.end());
        long long max_time = accumulate(arr.begin(), arr.end(), 0LL);

        while (min_time <= max_time)
        {
            long long curr_time = min_time + (max_time - min_time) / 2;

            if (isPossible(k, arr, curr_time))
            {
                max_time = curr_time - 1;
            }
            else
            {
                min_time = curr_time + 1;
            }
        }

        return (time * (min_time % 10000003) % 10000003);
    }
};

int main()
{
    int n, k, time;
    cout << "Enter number of boards: ";
    cin >> n;
    cout << "Enter number of painters: ";
    cin >> k;
    cout << "Enter time taken by one painter to paint 1 unit: ";
    cin >> time;
    vector<int> arr(n);
    cout << "Enter board lengths:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    Solution sol;
    int result = sol.paint(k, time, arr);
    cout << "Minimum time to paint all boards: " << result << endl;

    return 0;
}

/*
Time Complexity: O(N * log(S)), where N = number of boards, S = sum of all board lengths.
Space Complexity: O(1) extra (excluding input array).
*/
