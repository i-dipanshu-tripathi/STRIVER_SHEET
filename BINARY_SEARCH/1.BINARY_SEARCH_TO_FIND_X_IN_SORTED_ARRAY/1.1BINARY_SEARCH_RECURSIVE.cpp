#include <bits/stdc++.h>
using namespace std;

bool binarySearchRecursive(vector<int> &nums, int low, int high, int target)
{
    if (low > high)
        return false;

    int mid = low + (high - low) / 2;

    if (nums[mid] == target)
        return true;
    else if (nums[mid] > target)
        return binarySearchRecursive(nums, low, mid - 1, target);
    else
        return binarySearchRecursive(nums, mid + 1, high, target);
}

int main()
{
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter sorted elements:\n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter target to search: ";
    cin >> target;

    cout << "\nUsing Recursive Binary Search: ";
    if (binarySearchRecursive(nums, 0, n - 1, target))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}
