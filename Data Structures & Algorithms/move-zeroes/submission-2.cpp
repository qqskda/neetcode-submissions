class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int available = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                nums[available] = nums[i];
                if (available != i) nums[i] = 0;
                // check next available
                while (available <= i && nums[available] !=0 )
                {
                    available++;
                }
            }
        }
        return;
    }
};