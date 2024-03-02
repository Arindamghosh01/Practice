#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        
        for (int i= 0; i < n; i++) {
            int left = i+1, right = n-1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == 0)
                    s.insert({nums[i], nums[left], nums[right]}), left++, right--;
                else if (nums[i] + nums[left] + nums[right] > 0)
                    right--;
                else
                    left++;
            }
        }

        vector<vector<int>> ans;
        for (auto& i : s) ans.push_back(i);
        return ans; 
    }
};

int main() {
    Solution s;
    vector<int> x = {-1,0,1,2,-1,-4};
    vector<vector<int>> ret = s.threeSum(x);
    for (auto& x : ret) {
        for (auto &i : x) {
            cout << i << ' ';
        }
        cout << '\n'; 
    }
}