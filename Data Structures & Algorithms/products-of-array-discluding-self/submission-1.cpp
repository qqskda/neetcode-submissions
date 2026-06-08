class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // O(1) space

        int left = 1;
        int right = 1;
        vector<int> ret(nums.size(), 1);

        for (int i = 0; i < nums.size(); ++i)
        {
            ret[i] *= left;
            left *= nums[i];
        }

        for (int i = nums.size()-1; i >= 0; --i)
        {
            ret[i] *= right;
            right *= nums[i];
        }

        return ret;
    }
};
