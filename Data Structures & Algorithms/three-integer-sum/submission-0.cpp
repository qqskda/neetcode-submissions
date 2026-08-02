class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Use two pointers
        /*
        Outer loop O(N)
            Innter loop using two pointers => O(N)
                sum i + i+1 + n-1.
                if sum is > 0 meaning n-1 is too big so shrink
                if sum is < 0 meaning i+1 is too small so increase
                if sum == 0, update indexs so that j can be max, k can be min
                This is to avoid duplicate vals
        */
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        vector<vector<int>> ret;
        for (int i = 0; i < sz; ++i)
        {
            if (nums[i] > 0) break; 
            if (i>0 && nums[i] == nums[i-1]) continue;

            int left = i + 1;
            int right = sz - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum > 0) // right too big
                {
                    right--;
                }
                else if (sum < 0) // left too small
                {
                    left++;
                }
                else
                {
                    // sum is 0
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;

                    ret.push_back({nums[i], nums[left], nums[right]});

                    // Move on to next
                    left++;
                    right--;
                }
            }
        }
        return ret;
    }
};
