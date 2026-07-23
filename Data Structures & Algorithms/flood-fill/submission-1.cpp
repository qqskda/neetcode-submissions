class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image.front().size();

        int originalColor = image[sr][sc];

        if (originalColor == color) return image;

        // Using stack makes it dfs since we stk on top
        // Using queue makes it bfs since we care about the order
        stack<pair<int,int>> stk;

        stk.push({sr,sc});
        while (!stk.empty())
        {
            const auto [row,col] = stk.top();
            stk.pop();
            // 1. Check the curr color
            if (image[row][col] != originalColor)
            {
                continue;
            }

            // 2. update the color
            image[row][col] = color;

            // 3. push the adjacent into the stack
            if (row > 0)   stk.push({row-1, col});
            if (row < m-1) stk.push({row+1, col});
            if (col > 0)   stk.push({row, col-1});
            if (col < n-1) stk.push({row, col+1});
        }
        return image;
    }
};