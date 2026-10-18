class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int firstNum = nums[i];
            int j = i + 1, k = n - 1;
            while (j < k && j < n && k > 0) {
                int secondNum = nums[j], thirdNum = nums[k];
                if (firstNum + secondNum + thirdNum == 0) {
                    ans.push_back({firstNum, secondNum, thirdNum});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                } else if (firstNum + secondNum + thirdNum > 0) {
                    k--;
                } else
                    j++;
            }
        }
        return ans;
    }
};
