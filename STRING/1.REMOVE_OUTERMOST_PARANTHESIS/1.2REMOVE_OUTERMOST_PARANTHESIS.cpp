
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string removeOuterParentheses(string s) {
        // Time Complexity: O(n)
        // // Space Complexity: O(n)
        int openBracket = 0;
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(openBracket>0) ans += s[i];
                openBracket++;
            }
            else if(s[i]==')'){
                openBracket--;
                if(openBracket>0) ans += s[i];
            }
        }
        return ans;
    }
};

int main() {
    string s;
    cout << "Enter the parentheses string: ";
    cin >> s;
    Solution sol;
    string result = sol.removeOuterParentheses(s);
    cout << "Result: " << result << endl;
    return 0;
}