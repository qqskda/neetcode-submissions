class Solution {
public:
    int climbStairs(int n) {
        // Can climb 1 or 2

        // [1] => 1 (1) 
        // [2] => 1 1 / 2 (2) 
        // [3] => 1 1 1 / 1 2 / 2 1 (3)

        // [2] is [0] + [1]
        // [3] is [1] + [2] 

        if (n <= 2) return n;

        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; ++i )
        {
          dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
