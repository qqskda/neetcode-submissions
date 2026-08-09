class Solution {
public:
    vector<vector<int>> ret;
    void bt(const vector<int>& nums, vector<int>& tracker, vector<int>& curr)
    {
      if (curr.size() == nums.size())
      {
        ret.push_back(curr);
        return;
      }
      for (int i = 0; i < nums.size(); ++i)
      {
        if (tracker[i] == 0) continue;

        curr.push_back(nums[i]);
        tracker[i] = 0;
        bt(nums, tracker, curr);
        curr.pop_back();
        tracker[i] = 1;
      }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // 1 | 2 | 3

        // 1
        // 1 2 | 1 3
        // 1 2 3 | 1 3 2

        // 2
        // 2 1 | 2 3
        // 2 1 3 | 2 3 1

        // Use data structure to know which one has been used
        // Append from the early index if available

        // Given constraint: unique integers
        // Length can be 1 to 6 (likely due to complexity)

        int sz = nums.size();
        vector<int> tracker(sz,1);
        vector<int> curr = {};
        bt(nums, tracker, curr);
        return ret;
    }
};
