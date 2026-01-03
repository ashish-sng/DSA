// 329. Longest Increasing Path in a Matrix

class Solution {
public:
    int rows, columns;
    vector<vector<int>> dp;
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int dfs(int i, int j, vector<vector<int>>& matrix) {
        if (dp[i][j] != -1)
            return dp[i][j];

        int best = 1; // At least the cell itself

        for (auto& d : directions) {
            int nr = i + d[0];
            int nc = j + d[1];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < columns &&
                matrix[nr][nc] > matrix[i][j]) {
                best = max(best, 1 + dfs(nr, nc, matrix));
            }
        }

        dp[i][j] = best;
        return best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        columns = matrix[0].size();

        dp.assign(rows, vector<int>(columns, -1));

        int answer = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                answer = max(answer, dfs(i, j, matrix));
            }
        }

        return answer;
    }
};