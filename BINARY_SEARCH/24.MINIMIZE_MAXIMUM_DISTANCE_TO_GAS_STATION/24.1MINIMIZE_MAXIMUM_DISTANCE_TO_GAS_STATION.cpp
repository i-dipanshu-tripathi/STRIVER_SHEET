#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time: O(k * n), Space: O(n)
    double minimiseMaxDistance(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> howMany(n - 1, 0);
        for (int gasStations = 1; gasStations <= k; gasStations++)
        {
            double maxSection = -1;
            int maxInd = -1;
            for (int i = 0; i < n - 1; i++)
            {
                double diff = arr[i + 1] - arr[i];
                double sectionLength = diff / (howMany[i] + 1);
                if (sectionLength > maxSection)
                {
                    maxSection = sectionLength;
                    maxInd = i;
                }
            }
            howMany[maxInd]++;
        }
        double maxAns = -1;
        for (int i = 0; i < n - 1; i++)
        {
            double diff = arr[i + 1] - arr[i];
            double sectionLength = diff / (howMany[i] + 1);
            maxAns = max(maxAns, sectionLength);
        }
        return maxAns;
    }
};

int main()
{
    int n, k;
    cout << "Enter number of gas stations: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter positions of gas stations: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "Enter number of additional gas stations to add: ";
    cin >> k;

    Solution sol;
    double result = sol.minimiseMaxDistance(arr, k);
    cout << fixed << setprecision(6) << "Minimum possible maximum distance: " << result << endl;
    return 0;
}