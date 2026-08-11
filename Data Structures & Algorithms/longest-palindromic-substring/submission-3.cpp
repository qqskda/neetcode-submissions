class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        int bLeft = 0;
        int bLen  = 1;

        for (int center = 0; center < n; ++center)
        {
            // odd palindrome 
            int left = center;
            int right = center;

            while (left >= 0 && right < n && s[left] == s[right])
            {
                int len = right - left + 1;

                if (len > bLen)
                {
                    bLen = len;
                    bLeft = left;
                }
                --left;
                ++right;
            }
            // even palindrome
            left = center;
            right = center+1;

            while (left >= 0 && right < n && s[left] == s[right])
            {
                int len = right - left + 1;

                if (len > bLen)
                {
                    bLen = len;
                    bLeft = left;
                }
                --left;
                ++right;
            }
        }

        return s.substr(bLeft, bLen);
    }
};
