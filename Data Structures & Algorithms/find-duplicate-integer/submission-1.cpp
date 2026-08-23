class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // value = [1,n], input # = n+1.
        // One duplicate.

        // 1. use unordered_set or counting using array, size of n. Space: O(n)
        // 2. use sort. Time: O(n lg n) but we know the range so O(n) => bucket sort

        // Bucket sort approach:

        int n = nums.size() - 1;
        vector<int> bucket(n+1, 0);
        for (int num : nums) {
            bucket[num]++;
        }

        int index = 0;
        for (int value = 1; value <= n; ++value)
        {
            while (bucket[value] > 0)
            {
                nums[index] = value;
                bucket[value]--;
                index++;
            }
        }

        // find dup
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i-1]) return nums[i];
        }
        return -1;
    }
};
