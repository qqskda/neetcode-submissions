class Solution {
public:
    int maxArea(vector<int>& heights) {
        // value = distance * min(A, B)
        int left = 0;
        int right = heights.size()-1;

        int ret = 0;
        while (left < right)
        {
            ret = max((right-left) * min(heights[left], heights[right]), ret);

            if (heights[left] < heights[right]) left++;
            else right--;
        }
        return ret;
    }
};
