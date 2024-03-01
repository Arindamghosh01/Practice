class Solution {
public:
    // O(3*n) ~ O(n)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return nums;
        vector<int> prefix_product(n, 1);
        vector<int> reverse_product(n, 1);
        prefix_product[0] = nums[0];
        for (int i  = 1; i < n; i++) {
            prefix_product[i] = prefix_product[i-1] * nums[i]; 
        }
        

        reverse_product[n-1] = nums[n-1];
        for (int i  = n-2; i >= 0; i--) {
            reverse_product[i] = reverse_product[i+1] * nums[i]; 
        }

        vector<int> ans(n,1);
        for (int i = 1; i < n-1; i++) {
            ans[i] = prefix_product[i-1] * reverse_product[i+1];
        }
        ans[0] = reverse_product[1];
        ans[n-1] = prefix_product[n-2]; 
        return ans;
    }
};