class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // basically same as binary search using the first element of each row
        // like left, mid, right

        // once you find the row that nums[mid][0] < target && nums[right][0] > target
        // Check the row if it has the taret

        int left = 0, right = matrix.size()-1;
        while (left < right)
        {
            int mid = left + ((right-left+1)/2);
            
            // early return
            if (matrix[mid][0] == target) return true;

            if (matrix[mid][0] > target)
                right = mid-1;
            else // matrix[mid][0] <= target 
                left = mid;
        }

        // we now know the row
        int row = left;
        left = 0; right = matrix.front().size()-1;

        if (matrix[row][right] < target) return false;

        while (left <= right)
        {
            int mid = left + ((right-left)/2);

            if (matrix[row][mid] == target) return true;
            
            if (matrix[row][mid] < target)
                left = mid+1;
            else
                right = mid-1;
        }
        return false;
    }
};
