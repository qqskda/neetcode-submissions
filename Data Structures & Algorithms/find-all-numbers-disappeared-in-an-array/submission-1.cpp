class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // range [1, n] where n is nums.size();
        unordered_set<int> uset;
        uset.insert(nums.begin(), nums.end());

        vector<int> ret;
        ret.reserve(nums.size());
        for (int i = 1; i <= nums.size(); ++i)
        {
          if (!uset.contains(i)) ret.emplace_back(i);
        }
        return ret;
    }
};