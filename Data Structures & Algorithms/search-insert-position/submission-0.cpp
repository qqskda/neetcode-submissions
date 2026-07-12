class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Binary Search since it is ordered.
        // -1 0 2 4 6 8 
        // [0,5] mid = 2
        // [2,5] mid = 4
        // [3,5] mid = 6
        // [3,4] 
        

        int left = 0, right = nums.size();
        int mid = 0;
        while (left<right)
        {
          int mid = left + (right-left)/2;
          if (nums[mid] < target)
          {
            left = mid + 1;
          }
          else
          {
            right = mid;
          }
        }
        return left;
    }
};