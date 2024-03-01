class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, left = 0, right = height.size()-1;
        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            ans = max(ans, area);
            height[left] < height[right] ? left++ : right--;
        }
        return ans;
    }
};