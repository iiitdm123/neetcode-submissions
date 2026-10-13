class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1), suffix(n, 1), ans(n);
        for (int i = 0; i < n; i++) {
            if (i == 0)
                prefix[i] = nums[i];
            else
                prefix[i] = prefix[i - 1] * nums[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1)
                suffix[i] = nums[i];
            else
                suffix[i] = suffix[i + 1] * nums[i];
        }
        for (int i = 0; i < n; i++) {
            if (i == 0)
                ans[i] = suffix[i + 1];
            else if (i == n - 1)
                ans[i] = prefix[i - 1];
            else
                ans[i] = prefix[i - 1] * suffix[i + 1];
        }
        return ans;
    }
};
