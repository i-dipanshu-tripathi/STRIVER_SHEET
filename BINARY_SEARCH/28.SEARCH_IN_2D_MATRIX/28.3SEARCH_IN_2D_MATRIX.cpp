#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool searchMatrix(vector<vector<int>> &mat, int target){
            // better force approach 
            int low = 0;
            int row = mat.size();
            int col = mat[0].size();
            int high = row*col-1;
    
            while(low<=high){
                int mid = low + (high-low)/2;
    
                int curr_row = mid/col;
                int curr_col = mid%col;
    
                if(mat[curr_row][curr_col]==target){
                    return true;
                }
                else if(mat[curr_row][curr_col]>target){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
    
            return false;
        }
    };

int main() {
    Solution sol;
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    vector<vector<int>> mat(rows, vector<int>(cols));
    cout << "Enter the elements of the matrix row-wise:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> mat[i][j];
        }
    }
    int target;
    cout << "Enter the target value: ";
    cin >> target;
    if (sol.searchMatrix(mat, target)) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }
    return 0;
}

    