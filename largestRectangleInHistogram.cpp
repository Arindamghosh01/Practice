// https://www.youtube.com/watch?v=J2X70jj_I1o&list=PL_z_8CaSLPWdeOezg68SKkeLN4-T_jNHd&index=7
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> right(n, 0), left(n, 0);

        stack<int> s1;
        for (int i = 0; i < n; i++) {
            while (s1.size() && heights[s1.top()] >= heights[i]) {
                s1.pop();
            }
            if (s1.size())
                left[i] = i - s1.top();
            s1.push(i);
        }

        stack<int> s2;
        for (int i = n-1; i >= 0; i--) {
            while (s2.size() && heights[s2.top()] >= heights[i]) {
                s2.pop();
            }
            if(s2.size())
                right[i] = s2.top() - i;
            s2.push(i);
        }

        int ans = 0;
        for (int i = 0; i<n; i++) {
            int curr = 1 + (left[i] ? left[i] - 1: i) + 
                           (right[i] ? right[i] - 1 : n - i -1);
            ans = max (ans, heights[i] * curr);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> h = {2,1,5,6,2,3};
    cout << sol.largestRectangleArea(h);
}