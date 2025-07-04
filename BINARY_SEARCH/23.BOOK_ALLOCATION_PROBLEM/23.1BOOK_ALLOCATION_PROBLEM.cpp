#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int k, vector<int> &arr, int curr_time)
    {
        int n = arr.size();
        int paintersRequired = 1;
        int boardPaintedAreaTime = 0;

        for (int i = 0; i < n; i++)
        {
            if (boardPaintedAreaTime + arr[i] <= curr_time)
            {
                boardPaintedAreaTime += arr[i];
            }
            else
            {
                paintersRequired++;
                boardPaintedAreaTime = arr[i];
            }
        }

        return paintersRequired <= k;
    }
    int paint(int k, int time, vector<int> &arr)
    // Time Complexity: O((max_sum - max_element) * n)
    // Space Complexity: O(1)
    {
        int min_time = *max_element(arr.begin(), arr.end());
        int max_time = accumulate(arr.begin(), arr.end(), 0);

        for (int curr_time = min_time; curr_time <= max_time; curr_time++)
        {
            if (isPossible(k, arr, curr_time))
            {
                return time * curr_time;
            }
        }

        return -1;
    }
};

int main()
{
    int n, k, time;
    cout << "Enter number of boards: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter board lengths: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter number of painters: ";
    cin >> k;
    cout << "Enter time per unit: ";
    cin >> time;

    Solution sol;
    int result = sol.paint(k, time, arr);
    cout << "Minimum time required: " << result << endl;

    return 0;
}