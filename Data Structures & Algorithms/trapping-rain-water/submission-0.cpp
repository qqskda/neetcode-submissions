class Solution {
public:
    int trap(vector<int>& height) {
        // 1. if there is no block on left or right, we cannot trap water
        // 2. trap water at my index
        //  = min(left, right) * (min(left, right) - curr height).

        // heigh 0 2 0 3 1 0 1 3 2 1
        // left  0 0 2 2 3 3 3 3 3 3
        // right 3 3 3 3 3 3 3 2 1 0        
        // calc  0 0 2 0 2 3 2 0 0 0

        // collect left
        int left_max = 0;
        vector<int> left(height.size(), 0);
        for (int i = 0; i < height.size(); ++i)
        {
            // my left_max is the left_max collected in the previous
            left[i] = left_max;
            // This will be next index left_max
            left_max = max(left_max, height[i]);
        }

        // Collect right
        int right_max = 0;
        vector<int> right(height.size(), 0);
        for (int i = height.size()-1; i >= 0; --i)
        {
            right[i] = right_max;
            right_max = max(right_max, height[i]);
        }

        // Calculate
        int ret = 0;
        for (int i = 0; i < height.size(); i++)
        {
            int min_height = min(left[i], right[i]);
            if (height[i] > min_height) continue;

            int water = (min_height - height[i]);
            ret += water;
        }
        return ret;
    }
};
