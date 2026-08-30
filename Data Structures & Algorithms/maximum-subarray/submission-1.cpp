class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Subarray is contiguous
        // if subarray so far is less than a single number, 
        // there is no point of keeping that array. I can simply start new

        int subarray_sum = 0;
        int max_sum = INT_MIN;
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            
            // Either expanding subarray or start new
            subarray_sum = max(num, subarray_sum + num);

            // Track what has been the max
            max_sum = max(max_sum, subarray_sum);
        }
        return max_sum;
    }
};
