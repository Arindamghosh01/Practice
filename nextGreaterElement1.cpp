class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> ans(nums1.size(), 0);
        unordered_map<int, int> mp;

        for (int i = nums2.size()-1; i >=0; i--) {
            while (s.size() && s.top() <= nums2[i]) {
                s.pop();
            }
            mp[nums2[i]] = s.size() ? s.top() : -1;
            s.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++) {
            ans[i] = mp[nums1[i]];
        }

        return ans;
    } 
};