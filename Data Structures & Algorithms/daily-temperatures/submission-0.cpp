class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 30,38,30,36,35,40,28
        // st: [push 30, see 38, pop 30, push 38, push 30, pop 30, push 36, push 35, pop 35, pop 36,
        // pop 38, push 40, push 28]
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> s;
        for (int i = 0; i < n; i++) {
            if (s.empty() || temperatures[i] <= s.top().first) {
                s.push({temperatures[i], i});
            } else if (temperatures[i] > s.top().first) {
                while (!s.empty() && temperatures[i] > s.top().first) {
                    pair<int, int> current = s.top();
                    s.pop();
                    ans[current.second] = i - current.second;
                }
                s.push({temperatures[i], i});
            }
        }
        while (!s.empty()) {
            pair<int, int> current = s.top();
            s.pop();
            ans[current.second] = 0;
        }

        return ans;
    }
};
