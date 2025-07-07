#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double median(vector<int> &arr1, vector<int> &arr2)
    {

        //  Time Complexity: O((n1 + n2) * log(n1 + n2))
        //  Space Complexity: O(n1 + n2)

        vector<int> arr3;
        int n1 = arr1.size();
        int n2 = arr2.size();

        for (int i = 0; i < n1; i++)
        {
            arr3.push_back(arr1[i]);
        }

        for (int i = 0; i < n2; i++)
        {
            arr3.push_back(arr2[i]);
        }

        sort(arr3.begin(), arr3.end());
        int n3 = arr3.size();

        if (n3 % 2 == 0)
        {
            return (arr3[(n3 - 1) / 2] + arr3[n3 / 2]) / 2.0;
        }

        return arr3[n3 / 2];
    }
};

int main()
{
    int n1, n2;
    cout << "Enter sizes of the two arrays: ";
    cin >> n1 >> n2;
    vector<int> arr1(n1), arr2(n2);
    for (int i = 0; i < n1; ++i)
        cin >> arr1[i];
    for (int i = 0; i < n2; ++i)
        cin >> arr2[i];
    Solution sol;
    cout << fixed << setprecision(5) << sol.median(arr1, arr2) << endl;
    return 0;
}