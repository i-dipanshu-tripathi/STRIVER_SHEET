#include <bits/stdc++.h>
using namespace std;

bool binarySearchIterative(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return true;
        else if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

int main()
{
    int n, target;
    cout << "Enter number of elements: " << endl;
    cin >> n;

    vector<int> nums(n);
    cout << "Enter sorted elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << "Enter target to search: " << endl;
    cin >> target;

    cout << "\nUsing Iterative Binary Search: ";
    if (binarySearchIterative(nums, target))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}
