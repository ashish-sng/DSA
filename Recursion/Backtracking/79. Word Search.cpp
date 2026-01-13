// 79. Word Search

class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool backtrack(vector<vector<char>>& board, string& word, int ri, int ci,
                   int k) {
        if (board[ri][ci] == '#' || board[ri][ci] != word[k])
            return false;

        if (k == word.size() - 1)
            return true;

        char temp = board[ri][ci];
        board[ri][ci] = '#';

        for (auto& i : directions) {
            int nr = ri + i[0];
            int nc = ci + i[1];

            if (nr >= 0 && nr < board.size() && nc >= 0 &&
                nc < board[0].size()) {
                if (backtrack(board, word, nr, nc, k + 1)) {
                    return true;
                }
            }
        }

        board[ri][ci] = temp;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (backtrack(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};