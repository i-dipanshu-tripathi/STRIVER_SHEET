#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n), Space Complexity: O(n)
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        int i= n-1;
        while(i>=0){
            // trim trailing spaces 
            while(i>=0 && s[i]==' ') i--;
            string word = "";
            while(i>=0 && s[i]!=' '){
                word = s[i]+word;
                i--;
            }
            if(!ans.empty()) ans += " ";
            ans += word;
        }
        return ans;
    } 
};

int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);
    Solution sol;
    string result = sol.reverseWords(s);
    cout << "Reversed words: " << result << endl;
    return 0;
}