#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largeOddNum(string &s)
    {
        // Time Complexity: O(n) - single pass to remove leading zeros and another to find the rightmost odd digit.
        // Space Complexity: O(1) - only a few variables used, excluding the returned substring.
        int idx = 0;
        int n = s.size();

        while (idx < n && s[idx] == '0')
        {
            idx++;
        }

        for (int i = n - 1; i >= idx; i--)
        {
            int lastDigit = s[i] - '0';
            if (lastDigit % 2 == 1)
                return s.substr(idx, i + 1 - idx);
        }

        return "";
    }
};

int main()
{
    string input;
    cout << "Enter a string of digits: ";
    cin >> input;

    Solution sol;
    string result = sol.largeOddNum(input);

    if (!result.empty())
    {
        cout << "Largest odd number in the string: " << result << endl;
    }
    else
    {
        cout << "No odd number found in the string." << endl;
    }

    return 0;
}