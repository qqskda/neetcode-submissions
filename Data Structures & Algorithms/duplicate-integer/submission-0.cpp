class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> u_set;

        for (int num : nums)
        {
            if (u_set.contains(num))
            {
                return true;
            }
            u_set.insert(num);
        }
        return false;

    }
};