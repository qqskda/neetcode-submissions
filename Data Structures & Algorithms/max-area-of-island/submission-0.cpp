class Solution {
public:
    bool inBoundary(const vector<vector<int>>& grid, int i, int j)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        return i >= 0 && i < rows &&
               j >= 0 && j < cols;
    }

    int traverse(vector<vector<int>>& grid, int i, int j)
    {
        if (!inBoundary(grid, i, j)) return 0;

        if (grid[i][j] != 1) return 0;

        // mark as visited
        grid[i][j] = 0;
        int area = 1;

        area += traverse(grid, i + 1, j);
        area += traverse(grid, i - 1, j);
        area += traverse(grid, i, j + 1);
        area += traverse(grid, i, j - 1);
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ret = 0;

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                ret = max(ret, traverse(grid, i, j));
            }
        }
        return ret;
    }
};
