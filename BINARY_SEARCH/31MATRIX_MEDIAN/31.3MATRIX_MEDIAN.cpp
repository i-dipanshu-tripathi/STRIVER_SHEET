#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isPossible(vector<vector<int>>&matrix,int midElement){
        int count = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i=0;i<matrix.size();i++){
            count+= upper_bound(matrix[i].begin(),matrix[i].end(),midElement)-matrix[i].begin();
        }

        return count>=(rows*cols+1)/2;
    }
    int findMedian(vector<vector<int>>&matrix) {
        // Time Complexity: O(log(max-min) * r * log c), Space Complexity: O(1)
        int minElement = INT_MAX;
        int maxElement = INT_MIN;

        for(int i=0;i<matrix.size();i++){
            minElement = min(minElement,matrix[i][0]);
            maxElement = max(maxElement,matrix[i][matrix[0].size()-1]);
        }

        while(minElement<=maxElement){
            int midElement = minElement + (maxElement-minElement)/2;
            if(isPossible(matrix,midElement)){
                maxElement = midElement-1;
            }
            else{
                minElement = midElement+1;
            }
        }

        return minElement;
    }
};



int main() {
    int r, c;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;
    vector<vector<int>> matrix(r, vector<int>(c));
    cout << "Enter matrix elements:\n";
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            cin >> matrix[i][j];
        }
    }
    Solution sol;
    int median = sol.findMedian(matrix);
    cout << "Median of matrix: " << median << endl;
}