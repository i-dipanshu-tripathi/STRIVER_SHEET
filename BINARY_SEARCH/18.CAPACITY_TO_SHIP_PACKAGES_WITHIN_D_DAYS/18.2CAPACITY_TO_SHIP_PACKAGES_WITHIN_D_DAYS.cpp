#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &weights, int currCapacity, int days)
    {
        int noOfDaysRequired = 1;
        int currWeightLifted = 0;
        int n = weights.size();

        for (int i = 0; i < n; i++)
        {
            if (weights[i] > currCapacity)
            {
                return false;
            }
            else if (currWeightLifted + weights[i] <= currCapacity)
            {
                currWeightLifted += weights[i];
            }
            else
            {
                noOfDaysRequired++;
                currWeightLifted = weights[i];
            }
        }

        return noOfDaysRequired <= days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        // OPTIMAL APPROACH
        /*
            Space Complexity: O(1) extra (excluding input), O(N) for input array
            time Complexity: O(N * log(S)), where N = number of packages, S = sum of weights - max weight + 1
        */
        int minCapacity = *max_element(weights.begin(), weights.end());
        int maxCapacity = accumulate(weights.begin(), weights.end(), 0);

        while (minCapacity <= maxCapacity)
        {
            int currCapacity = minCapacity + (maxCapacity - minCapacity) / 2;

            if (isPossible(weights, currCapacity, days))
            {
                maxCapacity = currCapacity - 1;
            }
            else
            {
                minCapacity = currCapacity + 1;
            }
        }

        return minCapacity;
    }
};

int main()
{
    int n, days;
    cout << "Enter number of packages: ";
    cin >> n;
    vector<int> weights(n);
    cout << "Enter weights of packages: ";
    for (int i = 0; i < n; ++i)
        cin >> weights[i];
    cout << "Enter number of days: ";
    cin >> days;

    Solution sol;
    int result = sol.shipWithinDays(weights, days);
    cout << "Minimum capacity to ship within " << days << " days: " << result << endl;
    return 0;
}
