class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        // vector<int> right(n,0), left(n,0);
        // right[0] = prices[0];
        // for (int i = 1; i < n; i++) {
        // }

        // left[n-1] = prices[n-1];
        // for (int i = n-2; i >= 0; i--) {
        //     left[i] = max(left[i+1], prices[i]);
        // }
        
        // for (int i = 0; i < n; i++) {
        //     ans = max(ans, left[i]-right[i]);
        // }
        vector<int> m(n,0);
        m[0]=prices[0];
        for (int  i =1; i < n; i++) {
            m[i] = min(m[i-1], prices[i]);
            ans = max(ans, prices[i] - m[i]); 
        }
        return ans;
    }
};