class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Two arrays: one tracks of multiplication to left, one to the right
        // Then you need to multiply left and right.

        // nums:  1 2 4 6
        // left:  1 1 2 8
        // right: 48 24 6 1
        // ret :  48 24 12 8
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i)
        {
            left[i] = (nums[i-1] * left[i-1]);
        }
        for (int i = nums.size()-2; i >= 0; --i)
        {
            right[i] = (nums[i+1] * right[i+1]);
        }

        vector<int> ret(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            ret[i] = left[i] * right[i];
        }
        return ret;
        
    }
};
