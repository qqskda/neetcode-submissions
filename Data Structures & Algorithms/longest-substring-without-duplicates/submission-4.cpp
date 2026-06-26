class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Core logic: Once we found a duplicated char, substring started after the earlier dup char.
        // To do this, we have to: Track what is the current substring components, length, and each char's index.

        // zxy[z] => change substring to be xy[z]
        // zxy[y] => change substring to be [y]

        // Given condition: Char is ASCII (128 chars)
        // Length can be 0.

        // Base
        int len = s.length();
        if (len <= 1) return len;

        // unordered_map[char] = index.
        // We need start_index
        int start_index = 0;
        int maxlen = 0;
        int curlen = 0;
        unordered_map<char, int> umap;

        for (int i = 0; i < len; ++i)
        {
            if (umap.contains(s[i]))
            {
                // find dup
                // start_index could be past this dup already so we take max
                start_index = max(start_index,umap[s[i]]+1);
                maxlen = max(maxlen, curlen);
                curlen = i - start_index;
            }
            umap[s[i]] = i;
            ++curlen;
        }
        return max(maxlen, curlen);
    }
};
