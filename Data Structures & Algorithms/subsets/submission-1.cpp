class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // 0 -> []
        // 1 -> [1]
        // 2 -> [2] [1,2] [1]
        // 3 -> [3] [2,3] [1,2,3] [1,3]

        // n -> [n] + [] + (n-1)n

        // Need to remember prev (backtracking)

        int sz = nums.size();
        vector<vector<int>> ret = {{}};  // [[]]
        for (const int& num : nums)
        {
            // Save previous ret size
            int previousSize = ret.size();
            for (int i = 0; i < previousSize; ++i)
            {
                vector<int> curr = ret[i];
                curr.push_back(num);
                ret.push_back(move(curr));
            }
        }
        return ret;
    }
};
