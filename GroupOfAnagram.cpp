class Solution {
    int makehash(string str) {
        long long int hash = 1;

        for (const auto& c : str) {
            hash = (hash * (c * c + c + 9)) % 10000000007;
        }
        return hash;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<int, vector<string>> mp;

        for (const auto& str : strs) {
            int hash = makehash(str);
            mp[hash].push_back(str);
        }

        vector<vector<string>> res;

        for (const auto& [hash, group] : mp)
            res.push_back(group);

        return res;
    }
};