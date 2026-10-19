class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0 || n == 1) return 0;
        int l = 1, r = n - 2, ans = 0;
        int leftMax = height[0], rightMax = height[n - 1];
        while (l <= r) {
            if (leftMax < rightMax) {
                int water = leftMax - height[l];
                ans += max(water, 0);
                leftMax = max(leftMax, height[l]);
                l++;
            } else {
                int water = rightMax - height[r];
                ans += max(water, 0);
                rightMax = max(rightMax, height[r]);
                r--;
            }
        }
        return ans;
    }
};
