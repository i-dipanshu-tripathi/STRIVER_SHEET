#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumRateToEatBananas(vector<int> piles, int h)
    {

        /*
         * Time Complexity: O(N * M), where N is the number of piles and M is the maximum number of bananas in  any pile.
         * Space Complexity: O(1), excluding the input vector.
         */
        int n = piles.size();

        int maxSpeed = *max_element(piles.begin(), piles.end());

        for (int i = 1; i <= maxSpeed; i++)
        {
            double speed = i;
            double ans = 0;

            for (int i = 0; i < n; i++)
            {
                ans += ceil((piles[i] / speed));
            }

            if (ans <= h)
                return speed;
        }

        return maxSpeed;
    }
};

int main()
{
    int n, h;
    cin >> n >> h;
    vector<int> piles(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> piles[i];
    }
    Solution sol;
    cout << sol.minimumRateToEatBananas(piles, h) << endl;
    return 0;
}