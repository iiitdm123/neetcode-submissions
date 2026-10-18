class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return n;
        unordered_map<int, int> mp;
        int ans = 1;
        for (int num : nums) {
            if (mp[num] > 0) continue;
            mp[num] = 1 + mp[num - 1] + mp[num + 1];
            mp[num - mp[num - 1]] = mp[num];
            mp[num + mp[num + 1]] = mp[num];
            ans = max(ans, mp[num]);
        }
        return ans;
    }
};
