class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        vector<int> leftMax(n, 0), rightMax(n, 0);

        for (int i = 0; i < n; i++) {
            if (i == 0) continue;
            leftMax[i] = max(leftMax[i - 1], height[i - 1]);
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) continue;
            rightMax[i] = max(rightMax[i + 1], height[i + 1]);
        }
        for (int i = 0; i < n; i++) {
            int water = min(leftMax[i], rightMax[i]) - height[i];
            if (water > 0) ans += water;
        }
        return ans;
    }
};
