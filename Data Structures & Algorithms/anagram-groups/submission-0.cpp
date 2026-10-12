class Solution {
    vector<int> buildFrequencyMap(string s) {
        vector<int> freq(26, 0);
        for(char c : s) {
            freq[c-'a']++;
        }
        return freq;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<int>> mp;
        vector<vector<string>> ans;
        for (int i =0; i<strs.size(); i++) {
            mp[buildFrequencyMap(strs[i])].push_back(i);
        }
        for(auto i : mp) {
            vector<string> anagrams;
            for(auto index : i.second) {
                anagrams.push_back(strs[index]);
            }
            ans.push_back(anagrams);
        }
        return ans;

        
    }
};
