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
        // BETTER APPROACH

        // Time Complexity: O(N * log(S)), where N = number of books, S = sum of all pages
        // Space Complexity: O(1) (excluding input storage)
        if (m > nums.size())
            return -1;
        int minPages = *min_element(nums.begin(), nums.end());
        int maxPages = accumulate(nums.begin(), nums.end(), 0);

        while (minPages <= maxPages)
        {
            int currPages = minPages + (maxPages - minPages) / 2;

            if (isPossible(nums, m, currPages))
            {
                maxPages = currPages - 1;
            }
            else
            {
                minPages = currPages + 1;
            }
        }

        return minPages;
    }
};

int main()
{
    int n, m;
    cout << "Enter number of books: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter number of pages in each book: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    cout << "Enter number of students: ";
    cin >> m;

    Solution sol;
    int result = sol.findPages(nums, m);
    cout << "Minimum number of pages: " << result << endl;

    return 0;
}