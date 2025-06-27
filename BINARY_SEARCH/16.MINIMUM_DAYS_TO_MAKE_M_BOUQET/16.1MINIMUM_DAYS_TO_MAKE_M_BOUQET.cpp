class Solution
{
public:
    int roseGarden(int n, vector<int> nums, int k, int m)
    {
        // Space Complexity: O(1) (excluding input storage)
        // Time Complexity: O((maxBoomDay - minBoomDay + 1) * n), where n is the number of flowers.
        int minBoomDay = *min_element(nums.begin(), nums.end());
        int maxBoomDay = *max_element(nums.begin(), nums.end());

        if (m * k > n)
            return -1;

        for (int i = minBoomDay; i <= maxBoomDay; i++)
        {
            int flowerBoomed = 0;
            int noOfBouqets = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[j] <= i)
                {
                    flowerBoomed++;
                    if (flowerBoomed == k)
                    {
                        noOfBouqets++;
                        flowerBoomed = 0;
                    }
                }
                else
                {
                    flowerBoomed = 0;
                }
            }

            if (noOfBouqets >= m)
                return i;
        }

        return -1;
    }
};
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, m;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    cin >> k >> m;
    Solution sol;
    cout << sol.roseGarden(n, nums, k, m) << endl;
    return 0;
}