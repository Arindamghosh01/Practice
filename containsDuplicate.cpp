class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> freq;

        for (int i : nums) {
            if (freq.find(i) != freq.end())
                return true;
            else 
                freq.insert(i);
        }
        return false;
    }
};