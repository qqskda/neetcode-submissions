class Solution {
public:
    int rob(vector<int>& nums) {
        // DP problem
        // Keep tracks of max amount of money you robbed
        

        // dp[0] = nums[0]
        // dp[1] = max(nums[0],nums[1])

        // dp[n] is max robbed amount up to n
        // dp[2] = max(dp[0]+nums[2], dp[1])
        // dp[3] = max(dp[1]+nums[3], dp[2])
        // dp[n] = max(dp[n-2] + nums[n], dp[n-1]);

        // Since it is circle, we have to calculate twice
        // One including the first house and exclude the last
        // or
        // One excluding the first house and include the last
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        
        // Include the first hosue
        int pprev = nums[0];
        int prev = max(pprev, nums[1]);

        for (int i = 2; i < nums.size()-1; ++i)
        {
            int val = max(pprev + nums[i], prev);
            pprev = prev;
            prev = val;
        }

        int ret = max(pprev, prev);

        // Exlucde the first
        pprev = nums[1];
        prev = max(pprev, nums[2]);

        for (int i = 3; i < nums.size(); ++i)
        {
            int val = max(pprev + nums[i], prev);
            pprev = prev;
            prev = val;
        }
        int ret2 = max(pprev, prev);

        return max(ret, ret2);
    }
};
