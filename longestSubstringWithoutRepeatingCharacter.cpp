class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<int, int> mp;
        int n = s.length();
        int left = 0, right = 0;
        
        for (char c : s) {
            if (mp.find(c) == mp.end()) {
                mp[c]++;
            }
            else {
                while (c != s[left]) {
                    mp.erase(s[left]);
                    left++; 
                }
                left++;
            }
            right++;
            ans = max( ans, right - left);
        }
        return ans;
    }
};