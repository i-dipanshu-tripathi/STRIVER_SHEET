#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long floorSqrt(long long n)
    {
        long long ans = 0;
        for (int i = 1; i * i <= n; i++)
        {
            ans = i;
        }
        return ans;
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