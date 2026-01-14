// 200. Number of Islands

class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row,
             int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
            grid[row][col] == '0')
            return;
        if (visited[row][col])
            return;

        visited[row][col] = true;

        for (auto& i : directions) {
            dfs(grid, visited, row + i[0], col + i[1]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    count++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return count;
    }
};