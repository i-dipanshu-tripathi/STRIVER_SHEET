#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &nums, int student, int currPages)
    {
        int studentRequired = 1;
        int pagesRead = 0;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > currPages)
            {
                return false;
            }
            else if (nums[i] + pagesRead <= currPages)
            {
                pagesRead += nums[i];
            }
            else
            {
                studentRequired++;
                pagesRead = nums[i];
            }
        }

        return studentRequired <= student;
    }

    int findPages(vector<int> &nums, int m)
    {
        // BRUTE APPROACH
        if (m > nums.size())
            return -1;

        //  space_complexity O(1) - No extra space is used apart from a few variables.
        //  time_complexity O((maxPages - minPages + 1) * n) - For each possible page count,
        //  isPossible() is called, which takes O(n) time, where n is the number of books.

        int minPages = *min_element(nums.begin(), nums.end());
        int maxPages = accumulate(nums.begin(), nums.end(), 0);

        for (int i = minPages; i <= maxPages; i++)
        {
            if (isPossible(nums, m, i))
                return i;
        }

        return -1;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    Solution sol;
    int result = sol.findPages(nums, m);
    cout << result << endl;
    return 0;
}