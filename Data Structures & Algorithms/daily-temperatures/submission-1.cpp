class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && temperatures[i] > s.top().first) {
                pair<int, int> current = s.top();
                s.pop();
                ans[current.second] = i - current.second;
            }
            s.push({temperatures[i], i});
        }
        return ans;
    }
};
