class Solution {
public:
    int rob(vector<int>& nums) {
        // Backtracking: decision tree - travel available options
        // DP: Use the savepoints to avoid repeating same calculation

        // Cannot rub two adjacent houses
        // 1 1 3 3
        // [0] = nums[0] = 1
        // [1] = nums[1] = 1
        // [2] = [0] + nums[2] = 4;
        // [3] = [1] + nums[3] = 4;

        // 2 9 8 3 6
        // 2
        // 9
        // 10
        // 12
        // 16
        // [n] = max([n-2]+nums[n], [n-1]);

        int sz = nums.size();
        if (sz == 1) return nums[0];
        if (sz == 2) return max(nums[0], nums[1]);

        vector<int> dp(sz,0);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);

        for (int i = 2; i < sz; ++i)
        {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[sz-1];
    }
};
