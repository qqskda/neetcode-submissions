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

        // Easiest solution Use Queue
        // 1. Queue you can do FIFO with O(1)
        // 2. create fixed tracker array

        queue<char> chq;
        int tracker[128] = {0};
        int longest_sub = INT_MIN;

        for (int i = 0; i < len; ++i)
        {
            int chi = (int)s[i];
            if (tracker[chi])
            {
                // dup
                while (chq.front() != s[i])
                {
                    // Remove from the tracker before pop.
                    tracker[(int)chq.front()] = 0;
                    chq.pop();
                }
                chq.pop(); // Pop once more before we append ourselves
            }
            
            // Mark and append myself
            tracker[chi] = 1;
            chq.push(s[i]);
            longest_sub = max(longest_sub, (int)chq.size());
        }
        return longest_sub;
    }
};
