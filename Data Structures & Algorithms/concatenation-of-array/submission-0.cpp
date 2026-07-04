class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int sz = nums.size();
        nums.reserve(sz * 2);

        for (const int num : nums)
        {
            nums.emplace_back(num);
        }
        return nums;
    }
};