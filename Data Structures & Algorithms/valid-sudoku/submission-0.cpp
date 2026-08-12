class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // we are checking validity of sudoku, does not have to be solved.

        // Let's first try one codition at a time

        // Check each row's columns. See if column has a duplicates
        for (int row = 0; row < 9; ++row)
        {
            unordered_set<char> seen;
            for (int col = 0; col < 9; ++col)
            {
                char ch = board[row][col];
                if (ch == '.') continue;
                if (seen.contains(ch)) return false;
                seen.insert(ch);
            }
        }
        // Check each col's rows, see if row has a duplicates
        for (int col = 0; col < 9; ++col)
        {
            unordered_set<char> seen;
            for (int row = 0; row < 9; ++row)
            {
                char ch = board[row][col];
                if (ch == '.') continue;
                if (seen.contains(ch)) return false;
                seen.insert(ch);
            }
        }

        // square 1 => [0,0] - [0, 2] [2,0] - [2,2]
        // square 2 => [0,3] - [0, 5] [2,3] - [2,5]
        // square 3 => [0,6] - [0, 8] [2,6] - [2,8]
        // square 5 => [3,3] => [5,5]
        // square 8 => [6,6] => [8,8]
        for (int sq = 0; sq < 9; ++sq)
        {
            unordered_set<char> seen;
            for (int i = 0; i < 3; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    int row = (sq / 3) * 3 + i;
                    int col = (sq % 3) * 3 + j;
                    char ch = board[row][col];
                    if (ch == '.') continue;
                    if (seen.contains(ch)) return false;
                    seen.insert(ch);
                }
            }
        }
        return true;
    }
};
