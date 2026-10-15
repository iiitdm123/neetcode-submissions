class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        if (s.size() == 1)
            return 1;
        int curr=0, ans = 0, prev = INT_MIN;
        for(auto it : s) {
            if(prev != INT_MIN && it == prev+1) {
                curr++;
                
            }
            else {
                curr = 1;
            }
            ans = max(ans, curr);
            prev = it;
        } 
        return ans;

        
    }
};
