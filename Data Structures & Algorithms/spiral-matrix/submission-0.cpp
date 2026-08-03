class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // m * n

        // 0,0 -> 0,n -> 1,n -> m,n -> m,n-1 -> m, 0 -> m-1,0 -> 1,0 -> 1, n-1 -> ...

        int left = 0, right = matrix[0].size();
        int top = 0, bottom = matrix.size();

        vector<int> ret;
        while (left < right && top < bottom)
        {
            // Top: left to right
            for (int i = left; i < right; ++i)
            {
                ret.push_back(matrix[top][i]);
            }
            top++;

            // right: Top to bottom
            for (int i = top; i < bottom; ++i)
            {
                ret.push_back(matrix[i][right-1]);
            }
            right--;

            // Mid point check
            if (!(left < right && top < bottom)) {
                break;
            }
            // bottom: right to left
            for (int i = right-1; i >= left; --i)
            {
                ret.push_back(matrix[bottom-1][i]);
            }
            bottom--;

            // left: bottom to top
            for (int i = bottom-1; i>= top; --i)
            {
                ret.push_back(matrix[i][left]);
            }
            left++;
        }
        return ret;


    }
};
