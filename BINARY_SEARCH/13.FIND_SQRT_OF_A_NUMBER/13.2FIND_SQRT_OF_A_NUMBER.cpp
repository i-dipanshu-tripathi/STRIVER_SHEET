#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long floorSqrt(long long n)
    {
        long long low = 1;
        long long high = n;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;

            if (mid <= n / mid)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return high;
    }
};

int main()
{
    long long n;
    cout << "Enter a number: ";
    cin >> n;

    Solution sol;
    cout << "Floor square root: " << sol.floorSqrt(n) << endl;

    return 0;
}