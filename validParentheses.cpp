#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{')
            st.push(c);
        else {
            if (st.empty()) return false;
            if ((c == ')' && st.top() == '(') or
                (c == ']' && st.top() == '[') or
                (c == '}' && st.top() == '{')) 
            {
                st.pop();
            }
            else 
                return false;
        } 
    }
    return st.empty();
}

int main() {
    string s = "})";
    cout << isValid(s);
    return 0;
}