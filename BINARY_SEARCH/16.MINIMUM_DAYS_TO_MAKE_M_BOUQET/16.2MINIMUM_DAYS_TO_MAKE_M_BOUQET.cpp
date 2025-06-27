
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> nums, int currBoomDay, int k, int m)
    {
        int n = nums.size();
        int noOfBouqets = 0;
        int noOfFlowersBoomed = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= currBoomDay)
            {
                noOfFlowersBoomed++;
                if (noOfFlowersBoomed == k)
                {
                    noOfBouqets++;
                    noOfFlowersBoomed = 0;
                }
            }
            else
            {
                noOfFlowersBoomed = 0;
            }
        }
        return noOfBouqets >= m;
    }

    int roseGarden(int n, vector<int> nums, int k, int m)
    {
        // Time Complexity: O(n * log(D)), where n = number of flowers, D = (max bloom day - min bloom day)
        // Space Complexity: O(1) extra space (excluding input)
        int minBoomDay = *min_element(nums.begin(), nums.end());
        int maxBoomDay = *max_element(nums.begin(), nums.end());

        if (m * k > n)
            return -1;

        while (minBoomDay <= maxBoomDay)
        {
            int currBoomDay = minBoomDay + (maxBoomDay - minBoomDay) / 2;
            if (isPossible(nums, currBoomDay, k, m))
            {
                maxBoomDay = currBoomDay - 1;
            }
            else
            {
                minBoomDay = currBoomDay + 1;
            }
        }

        return minBoomDay;
    }
};

int main()
{
    int n, k, m;
    cout << "Enter number of flowers (n): ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter bloom days for each flower:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    cout << "Enter k (flowers per bouquet): ";
    cin >> k;
    cout << "Enter m (number of bouquets): ";
    cin >> m;

    Solution sol;
    int result = sol.roseGarden(n, nums, k, m);
    cout << "Minimum days to make " << m << " bouquets: " << result << endl;
    return 0;
}