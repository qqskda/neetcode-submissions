class Solution {
public:
    void backtrack(const vector<int>& nums, int index, vector<int>& curr, vector<vector<int>>& ret)
    {
        ret.push_back(curr);

        for (int i = index; i < nums.size(); ++i)
        {
            curr.push_back(nums[i]);
            backtrack(nums, i + 1, curr, ret);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> curr = {};

        backtrack(nums, 0, curr, ret);
        return ret;
    }
};
