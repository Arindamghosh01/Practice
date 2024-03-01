class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int& i: nums)
            mp[i]++;
                
        set<pair<int, int>> s;
        for (auto& i : mp)
            s.insert({i.second, i.first});

        vector<int> ans;
        for (auto i = s.rbegin(); i != s.rend(); i++) {
            if (k--)
                ans.push_back(i->second);
            else 
                break;
        }
        return ans;
    }
};