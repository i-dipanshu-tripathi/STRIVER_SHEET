
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string removeOuterParentheses(string s) {
        // Time Complexity: O(n)
        // Space Complexity: O(n)
        int openBracketCount = 0;
        string ans = "";
        string temp = "";
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
                openBracketCount++;
            }
            else if(s[i]==')'){
                openBracketCount--;
                if(openBracketCount==0){
                    while(st.size()>1){
                        temp=st.top()+temp;
                        st.pop();
                    }
                    st.pop();
                    ans =  ans+temp;
                    temp="";
                }
                else{
                    st.push(s[i]);
                }
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
