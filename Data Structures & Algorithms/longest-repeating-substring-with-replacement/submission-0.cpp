class Solution {
   public:
    int characterReplacement(string s, int k) {
        int ans = 0, n = s.length(), l = 0, maxf = 0;
        unordered_map<char, int> count;
        for (int r = 0; r < n; r++) {
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);
            while ((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
