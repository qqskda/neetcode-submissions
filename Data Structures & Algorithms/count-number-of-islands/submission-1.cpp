class Solution {
public:
    void traverse(vector<vector<char>>& grid, int i, int j)
    {
        if(!inBoundary(grid, i, j)) return; // out of boundary

        if(grid[i][j] != '1') return; //we have been here or not island

        grid[i][j] = '0';
        traverse(grid, i+1, j);
        traverse(grid, i-1, j);
        traverse(grid, i, j+1);
        traverse(grid, i, j-1);
    }
    bool inBoundary(const vector<vector<char>>& grid, int i, int j)
    {
        int rows = grid.size()-1;
        int cols = grid.front().size()-1;

        if (i >= 0 && i <= rows && j >= 0 && j <= cols) return true;
        else return false;
    }
    int numIslands(vector<vector<char>>& grid) {
        // To me, it looks like it can be done via dp (memoization) with either 
        // DFS or BFS

        // Q: How can we distinguish the each island?
        // A: Start from an island, and mark the visited ones once we are done with the island, we will keep going and check through unvisited place => new island
        // Repeat it over
        int islands = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++islands; // new island!
                    traverse(grid, i, j);
                }
            }
        }
        return islands;
    }
};
