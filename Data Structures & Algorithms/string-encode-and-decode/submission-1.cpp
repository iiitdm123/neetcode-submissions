class Solution {
   public:
    string delimit = "yash";
    string encode(vector<string>& strs) {
        string ans;
        for (auto s : strs) {
            ans = ans + s + delimit;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int start = 0, pos;
        while ((pos = s.find(delimit, start)) != string::npos) {
            ans.push_back(s.substr(start, pos - start));
            start = pos + delimit.length();
        }
        return ans;
    }
};
