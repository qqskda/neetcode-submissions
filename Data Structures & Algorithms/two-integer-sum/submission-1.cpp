class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;
        seen.reserve(nums.size()); // To avoid unncessary memory re-allocation  (nums.length <= 1000)

        for (int i = 0; i < nums.size(); ++i)
        {
            unordered_map<int,int>::iterator itr = seen.find(target-nums[i]);
            if (itr != seen.end())
            {
                return {itr->second, i};
            }
            seen.emplace(nums[i], i);
        }
        return {};

    }
};
