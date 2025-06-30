#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        /*
         * Time Complexity: O((sum(weights) - max(weights)) * n), where n is the number of packages.
         * This is because for each possible capacity in the range, we simulate the shipping process.
         * Space Complexity: O(1), excluding the input vector.
         */
        int minCapacity = *max_element(weights.begin(), weights.end());
        int maxCapacity = accumulate(weights.begin(), weights.end(), 0);

        int n = weights.size();

        for (int curr_weight = minCapacity; curr_weight <= maxCapacity; curr_weight++)
        {
            int noOfDaysRequired = 1;
            int net_weight = 0;
            for (int i = 0; i < n; i++)
            {
                if (weights[i] + net_weight <= curr_weight)
                {
                    net_weight += weights[i];
                }
                else
                {
                    noOfDaysRequired++;
                    net_weight = weights[i];
                }
            }

            if (noOfDaysRequired <= days)
            {
                return curr_weight;
            }
        }

        return -1;
    }
};

int main()
{
    int n, days;
    cout << "Enter number of packages: ";
    cin >> n;
    vector<int> weights(n);
    cout << "Enter weights: ";
    for (int i = 0; i < n; ++i)
        cin >> weights[i];
    cout << "Enter number of days: ";
    cin >> days;

    Solution sol;
    int result = sol.shipWithinDays(weights, days);
    cout << "Minimum capacity required: " << result << endl;
    return 0;
}