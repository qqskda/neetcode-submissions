class Solution {
public:
    int characterReplacement(string s, int k) {
        // Need to know the frequency of most one.
        // Valid window = sum of rest freq <= k;

        // Update freq -> check validity
        // if non valid => shrink
        // if valid => expand
        array<int,26> freq = {0};
        int left = 0; int right = 0;
        int sz = s.length();
        int max_window = 0;
        int max_freq = 0;
        while (right < sz)
        {
            int li = s[left]-'A';
            int ri = s[right]-'A';
            ++freq[ri];
            max_freq = max(max_freq, freq[ri]);
            int curr_window = right-left+1;
            int mostFreq = max_freq;

            if (mostFreq + k < curr_window)
            {
                // this is invalid window
                --freq[li];
                ++left;
            }
            else
            {
                // curr_window is valid
                max_window = max(max_window, curr_window);
            }
            ++right;
        }
        return max_window;
    }
};
