class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // [1, n], and nums.size() = n+1.
        // nums.size() = n+1 => pigeonhole principle, at least one is duplciate

        // It is guaranteed to have a duplicate.

        // Cycle detection can be used in this case. Use the value as an index

        int slow = nums[0];
        int fast = nums[0];

        do 
        {
            slow = nums[slow]; // it is like node->next 
            fast = nums[nums[fast]]; // node->next->next
        } while (slow != fast);
        // slow met fast => both are in the cycle, but we do not know if they met at the
        // duplicated place

        slow = nums[0]; // reset slow
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
        

    }
};
