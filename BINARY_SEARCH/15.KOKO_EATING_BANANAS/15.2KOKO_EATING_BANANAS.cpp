#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double calculateTime(vector<int> nums, int curr_speed)
    {
        double time = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            time += ceil(((1.0 * nums[i]) / curr_speed));
        }

        return time;
    }
    int minimumRateToEatBananas(vector<int> nums, int h)
    {
        // Time Complexity: O(N * log M), where N = nums.size(), M = max(nums)
        // Space Complexity: O(1) (excluding input storage)
        int n = nums.size();
        int low_speed = 1;
        int high_speed = *max_element(nums.begin(), nums.end());

        while (low_speed <= high_speed)
        {
            int curr_speed = low_speed + (high_speed - low_speed) / 2;

            double timeTaken = calculateTime(nums, curr_speed);

            if (timeTaken <= h)
            {
                high_speed = curr_speed - 1;
            }
            else
            {
                low_speed = curr_speed + 1;
            }
        }

        return low_speed;
    }
};

int main()
{
    vector<int> nums = {3, 6, 7, 11};
    int h = 8;
    Solution sol;
    int minRate = sol.minimumRateToEatBananas(nums, h);
    cout << "Minimum rate to eat all bananas in " << h << " hours: " << minRate << endl;
    return 0;
}
