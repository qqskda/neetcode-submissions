class Solution {
public:
  vector<vector<int>> ret;
    void bt(const vector<int>& nums, vector<int>& curr, int index)
    {
      for (int i = index; i < nums.size(); ++i)
      {
        if (i > index && nums[i] == nums[i - 1]) continue;
        curr.push_back(nums[i]);
        ret.push_back(curr);
        bt(nums, curr, i+1);
        curr.pop_back();
      }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // [1] [2] and [2] [1] are considered as identical
        // it cares about values, not the index item.
        // Return order does not matter => we can sort the nums

        // 1 1 2
        // []
        // [1]
        // [1] [1]
        // [1] [1] [2]
        // [1] [2]
        // [2]
        sort(nums.begin(), nums.end());
        vector<int> curr = {};
        ret.push_back({});
        bt(nums, curr, 0);
        return ret;
        // return {{}, {1}, {1,1}, {1,2}, {1,1,2}, {2}};
    }
};
