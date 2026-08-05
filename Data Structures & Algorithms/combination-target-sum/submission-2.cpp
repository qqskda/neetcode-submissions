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

        for (int i = index; i < nums.size(); ++i)
        {
            if (target - nums[i] < 0) return;
            curr.push_back(nums[i]);
            backtrack(ret, nums, curr, target-nums[i], i);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        vector<int> curr = {};
        sort(nums.begin(), nums.end());
        backtrack(ret, nums, curr, target, 0);
        return ret;
    }
};
