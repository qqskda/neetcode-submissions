class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 1. Using unordered_map<string, vector<string>>
        // => key: we put sorted string, value: vector of the anagrams.

        unordered_map<string, vector<string>> anagrams;

        // 2. we do not care about index
        for (const string& str : strs)
        {
            string sorted = str; // copy constructor implicitly called
            sort(sorted.begin(), sorted.end());
            anagrams[sorted].emplace_back(str);
        }

        // 3. Flatten the map to vector
        vector<vector<string>> ret;
        ret.reserve(anagrams.size()); 

        for (const auto& [key, vec] : anagrams)
        {
            ret.emplace_back(std::move(vec));
        }
        return ret;
    }
};
