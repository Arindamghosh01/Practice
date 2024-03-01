class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans = 0;
        for (int i: nums) s.insert(i);
        for (int i : nums) {
            if (s.find(i-1) == s.end()) {
                int currEle = i, currLen = 1;
                while (s.find(currEle+1) != s.end()) {
                    currEle++; currLen++;         
                }
                ans = max(ans, currLen);
            }        
        }
        return ans;
    }
};