class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        anagrams.reserve(strs.size());

        for (const string& str : strs)
        {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            anagrams[sorted].emplace_back(str);
        }

        vector<vector<string>> ret;
        ret.reserve(anagrams.size());
        for (const auto& [key, value] : anagrams)
        {
            // Move is okay here since anagrams will be desconstructed and never be used later
            ret.emplace_back(std::move(value));
        }
        return ret;
    }
};
