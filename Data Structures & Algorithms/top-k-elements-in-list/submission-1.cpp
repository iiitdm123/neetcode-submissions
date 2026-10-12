class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        map<int, vector<int>> reverse_freq;
        vector<int> ans;
        for (int i : nums) {
            freq[i]++;
        }
        for (auto i : freq) {
            reverse_freq[i.second].push_back(i.first);
        }
        for (auto i = reverse_freq.rbegin(); i != reverse_freq.rend(); i++) {
            for (auto j : i->second) {
                ans.push_back(j);
            }

            if (ans.size() == k) break;
        }
        return ans;
    }
};
