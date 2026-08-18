class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Find pivot point

        int left = 0, right = nums.size()-1;

        while (left < right)
        {
            int mid = left + ((right-left)/2);

            if (nums[mid] > nums[right]) // has pivot between [mid, right]
                left = mid+1;
            else // nums[mid] <= nums[right] => has privot between [left,mid]
                right = mid;
        }
        int pivot = left;

        // Pivot can be used as a point where we can divide the nums to left and right
        left = 0; right = nums.size()-1;

        if (target >= nums[pivot] && target <= nums[right])
            left = pivot; //right side
        else
            right = pivot-1; //left side
        
        while (left<=right)
        {
            int mid = left + ((right-left)/2);

            if (nums[mid] == target) return mid;

            if (nums[mid] < target)
                left = mid+1;
            else
                right = mid-1;
        }
        return -1;

    }
};
