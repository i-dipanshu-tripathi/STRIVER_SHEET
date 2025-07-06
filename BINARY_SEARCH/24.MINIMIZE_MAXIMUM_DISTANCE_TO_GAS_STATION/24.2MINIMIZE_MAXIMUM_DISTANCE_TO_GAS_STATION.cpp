#include <bits/stdc++.h>
using namespace std;

// Space Complexity: O(1), Time Complexity: O(n * log(max_distance/diff))

class Solution
{
private:
    int numberOfGasStationsRequired(long double dist, vector<int> &arr)
    {
        int n = arr.size();
        int cnt = 0;
        for (int i = 1; i < n; i++)
        {
            int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
            if ((arr[i] - arr[i - 1]) == (dist * numberInBetween))
            {
                numberInBetween--;
            }
            cnt += numberInBetween;
        }
        return cnt;
    }

public:
    long double minimiseMaxDistance(vector<int> &arr, int k)
    {
        int n = arr.size();
        long double low = 0;
        long double high = 0;
        for (int i = 0; i < n - 1; i++)
        {
            high = max(high, (long double)(arr[i + 1] - arr[i]));
        }
        long double diff = 1e-6;
        while (high - low > diff)
        {
            long double mid = (low + high) / 2.0;
            int cnt = numberOfGasStationsRequired(mid, arr);
            if (cnt <= k)
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        return high;
    }
};

int main()
{
    int n, k;
    cout << "Enter number of gas stations: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter positions of gas stations (sorted): ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "Enter number of additional gas stations to add: ";
    cin >> k;
    Solution sol;
    long double ans = sol.minimiseMaxDistance(arr, k);
    cout << fixed << setprecision(6) << "Minimum possible maximum distance: " << ans << endl;
    return 0;
}