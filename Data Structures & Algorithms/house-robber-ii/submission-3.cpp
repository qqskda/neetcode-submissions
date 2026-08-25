class Solution {
public:
    int helper(const vector<int>& nums, const int start, const int end)
    {
        
        int pprev = 0;
        int prev = 0;

        for (int i = start; i < end; ++i)
        {
            int val = max(pprev + nums[i], prev);
            pprev = prev;
            prev = val;
        }

        return max(pprev, prev);
    }
    int rob(vector<int>& nums) {
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
        int sz = nums.size();

        if (sz == 1) return nums[0];
        return max(helper(nums,0,sz-1), helper(nums,1,sz));
    }
};
