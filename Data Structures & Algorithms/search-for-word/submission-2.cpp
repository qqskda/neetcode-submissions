class Solution {
 public:
  bool bt(const vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col,
          string target) {

    // we have been here
    if (visited[row][col]) return false;
    // if not empty, our travel goes on
    if (board[row][col] != target.front()) return false;
    // we check horizontally or vertically neighboring cells.

    // but we cannot use the same one again
    // This might be problem if we have like spiral
    if (target.length() == 1) return true;
    // 1. mark the current location, and update str we look for
    visited[row][col] = true;
    string newTarget = target.substr(1);
    // 2. check the neighbour
    if (row > 0 && bt(board, visited, row - 1, col, newTarget)) return true;
    if (col > 0 && bt(board, visited, row, col - 1, newTarget)) return true;
    if (row < board.size()-1 && bt(board, visited, row + 1, col, newTarget)) return true;
    if (col < board[0].size()-1 && bt(board, visited, row, col + 1, newTarget)) return true;
    visited[row][col] = false;
    return false;
  }

  bool exist(vector<vector<char>>& board, string word) {
    // DFS+backtracking

    // 1. Find the first char to start from
    // 2. check its neighbour for next char
    // 2.1 Note there could be multiple options

    // I need to know which char I am looking for.
    int szi = board.size();
    int szj = board[0].size();
    vector<vector<bool>> visited(szi, vector<bool>(szj, false));
    for (int i = 0; i < szi; ++i) {
      for (int j = 0; j < szj; ++j) {
        if (bt(board, visited, i, j, word)) return true;
      }
    }
    return false;
  }
};
