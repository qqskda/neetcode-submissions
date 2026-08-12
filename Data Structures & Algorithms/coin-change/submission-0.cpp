class Solution {
public:
    int dpf(const vector<int>& coins, vector<int>& dp, int amount)
    {
        if (amount < 0) return -1; // not possible

        if (dp[amount] != -2)
        {
            // we have been here
            return dp[amount];
        }

        int bestMin = INT_MAX;
        for (const int& coin : coins)
        {
            int target = amount - coin;
            int output = dpf(coins, dp, target);
            if (output >= 0)
            {
                bestMin = min(bestMin, output);
            }
        }
        dp[amount] = (bestMin == INT_MAX) ? -1 : bestMin + 1;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // amount 12, 1 5 10
        // minCoins (12) = min(minCoins(11), minCoins(7), minCoins(2)) + 1;
        // ... minCoins(1) = min(minCoins(0), minCoins(-4), minCoins(-9)) + 1;

        vector<int> dp(amount+1,-2);
        dp[0] = 0;
        return dpf(coins, dp, amount);
    }
};
