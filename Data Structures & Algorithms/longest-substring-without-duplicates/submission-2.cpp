class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0, n = s.length();
        int start = 1, end = 1;
        while (start <= n && end <= n) {
            if (!mp[s[end-1]]) {
                mp[s[end-1]] = end;
                ans = max(ans, end - start + 1);
                end++;

            } else {
                start = max(start, mp[s[end-1]] + 1);
                mp[s[end-1]] = end;
                ans = max(ans, end - start + 1);
                end++;
            }
            // abba
            //mp[a] = 1
            //mp[b] = 2
            //start = 3, currans = 1,
            //mp[a] = 4, start = 2
        }
        return ans;
    }
};
