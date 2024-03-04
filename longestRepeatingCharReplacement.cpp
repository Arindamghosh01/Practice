class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), left = 0, right = 0;
        int maxFreq = 0;
        unordered_map<int, int> mp;
        int ans = 0, currlen = 0;
        for (char& c : s) {
            mp[c]++;
            maxFreq = max(maxFreq, mp[c]);
            currlen = right - left + 1;
            if (currlen - maxFreq > k) {
                mp[s[left]]--;
                left++;
            }
            else {
                ans = max (ans, currlen);
            }
            right++;
        }
        return ans;
    }
};