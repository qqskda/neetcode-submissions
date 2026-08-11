class Solution {
public:
    int robRange(const vector<int>& nums, int start, int end) {
        int pprev = 0;
        int prev = 0;

        for (int i = start; i <= end; ++i) {
            int curr = max(pprev + nums[i], prev);

            pprev = prev;
            prev = curr;
        }

        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        return max(
            robRange(nums, 0, n - 2), // don't use last
            robRange(nums, 1, n - 1)  // don't use first
        );
    }
};