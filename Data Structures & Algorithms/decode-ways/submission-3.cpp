class Solution {
public:
    int numDecodings(string s) {
        // 1. a number cannot start with zero
        // 2. a number is [1,26] => a digit or two

        // DP question 
        // 1012
        // 101 2 (i=3) 
        // 10 1 2 (i=2) => it includes i = 3
        // 10 12 (i=2)
        // dp[i] = # ways to decdoe from ith to the end

        int n = s.length();

        vector<int> dp(n+1, -1);
        dp[n] = 1;

        for (int i = n-1; i >= 0; --i)
        {
            if (s[i] == '0')
            {
                dp[i] = 0;
                continue;
            }

            // one way
            dp[i] = dp[i+1];

            // two way
            if (i+1 < n)
            {
                int value = (s[i]-'0') * 10 + (s[i+1]-'0');
                if (value > 0 && value <= 26)
                    dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};
