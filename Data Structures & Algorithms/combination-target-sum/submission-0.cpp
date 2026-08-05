class Solution {
public:
    void backtrack(
        vector<vector<int>> &ret,
        const vector<int> &nums,
        vector<int> &curr,
        int target,
        int index
    )
    {
        if (target == 0)
        {
            ret.push_back(curr);
            return;
        }
        if (target < 0 || index >= nums.size())
            return;

        // Try with the current index
        curr.push_back(nums[index]);
        backtrack(ret, nums, curr, target-nums[index], index);
        curr.pop_back();
        // Do not add the current one, we move forward
        backtrack(ret, nums, curr, target, index + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        vector<int> curr = {};
        backtrack(ret, nums, curr, target, 0);
        return ret;
    }
};
