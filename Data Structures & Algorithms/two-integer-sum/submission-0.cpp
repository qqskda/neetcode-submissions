class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 1. A+B = Target => Target - A = B
        // 2. We need to return index => we need to store index
        // 3. Return smaller index first.
        // 4. nums is ordered.

        // A. No sets, but maps or sets of pair. probably maps
        unordered_map<int, int> indexed;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (indexed.find(target-nums[i]) != indexed.end())
                return {indexed[target-nums[i]], i};

            indexed.emplace(nums[i], i);
        }

        return {};

    }
};
