class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0, rightMax = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) continue;
            rightMax = max(rightMax, prices[i + 1]);
            ans = max(ans, rightMax - prices[i]);
        }
        return ans;
    }
};
