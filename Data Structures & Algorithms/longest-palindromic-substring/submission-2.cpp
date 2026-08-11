class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int bestStart = 0;
        int bestLen = 1;

        // Expand around every possible center
        for (int center = 0; center < n; ++center) {

            // Odd length palindrome
            // Example: "aba"
            int left = center;
            int right = center;

            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;

                if (len > bestLen) {
                    bestLen = len;
                    bestStart = left;
                }

                --left;
                ++right;
            }

            // Even length palindrome
            // Example: "abba"
            left = center;
            right = center + 1;

            while (left >= 0 && right < n && s[left] == s[right]) {
                int len = right - left + 1;

                if (len > bestLen) {
                    bestLen = len;
                    bestStart = left;
                }

                --left;
                ++right;
            }
        }

        return s.substr(bestStart, bestLen);
    }
};