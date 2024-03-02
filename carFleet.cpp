class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end());

        stack<float> s;
        for (int i = 0; i < n; i++) {
            float time = (target - v[i].first) /(float)v[i].second;
            while (s.size() && s.top() <= time) {
                s.pop();
            }
            s.push(time);
        }
        return s.size();
    }
};