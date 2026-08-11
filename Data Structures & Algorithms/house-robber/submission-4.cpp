class Solution {
   public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 1) return nums[0];
        if (sz == 2) return max(nums[0], nums[1]);

        int pprev = nums[0];
        int prev = max(nums[0], nums[1]);

        for (int i = 2; i < sz; ++i) {
            int curr = max(pprev + nums[i], prev);
            pprev = prev;
            prev = curr;
        }
        return prev;
    }
};
