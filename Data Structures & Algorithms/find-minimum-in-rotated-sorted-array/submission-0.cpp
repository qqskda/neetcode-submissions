class Solution {
public:
    int findMin(vector<int> &nums) {
        // simply find the pivot point
        int left = 0; int right = nums.size()-1;

        while (left < right)
        {
            // left bias midpoint
            int mid = left + ((right-left)/2);

            if (nums[mid] > nums[right]) // pivot point is in between [mid+1,right]
                left = mid+1;
            else // pivot point is in between [left,mid]
                right = mid;
        }
        return nums[left];

    }
};
