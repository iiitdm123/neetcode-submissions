class Solution {
   public:
    char delimiter = '#';

    string encode(vector<string>& strs) {
        string s;
        for (string str : strs) {
            s = s + to_string(str.length()) + delimiter + str;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        //5#hello5#world 
        while (i < s.length()) {
            int j = i;
            while (s[j] != delimiter) j++;
            int string_length = stoi(s.substr(i, j-i));
            string decoded = s.substr(j+1, string_length);
            ans.push_back(decoded);
            i = j + string_length + 1;
        }
        return ans;
    }
};
