class Solution {
public:
    string minWindow(string s, string t) {
        // base
        if (s.length() < t.length()) return "";

        unordered_map<char, int> need;
        for (char ch : t) need[ch]++;

        unordered_map<char, int> window;
        int left = 0;
        int bestLeft = 0;
        int bestLen = INT_MAX;

        int formed = 0;
        int required = need.size();

        for (int right = 0; right < s.size(); ++right)
        {
            char ch = s[right];
            window[ch]++;

            if (need.contains(ch) && window[ch] == need[ch])
                formed++; // one char satisfied the condition

            while (formed == required) // when all the conditions are satisfied
            {
                int len = right - left + 1;
                if (len < bestLen)
                {
                    bestLen = len;
                    bestLeft = left;
                }

                // We recorded the substring, now lets shrink
                char leftCh = s[left];
                window[leftCh]--;

                if (need.contains(leftCh) && window[leftCh] < need[leftCh])
                    formed--; // this was the char we cared and we lost
                
                left++;
            }
        }
        if (bestLen == INT_MAX) return "";

        return s.substr(bestLeft, bestLen);
    }
};
