#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool searchMatrix(vector<vector<int>> &mat, int target){
            // better force approach 
            int rows = mat.size();
            int cols = mat[0].size();
    
            int curr_row = 0;
            int curr_col = cols-1;
    
            while(curr_row<rows && curr_col>=0){
                if(mat[curr_row][curr_col]==target){
                    return true;
                }
                else if(target<mat[curr_row][curr_col]){
                    curr_col = curr_col-1;
                }
                else{
                    curr_row = curr_row+1;
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

    