class Solution {
private:
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};

public:
    void DFS(vector<vector<char>>& grid, vector<vector<int>>& visited, int i,
             int j) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == '0' ||
            visited[i][j] == 1)
            return;

        visited[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int newI = i + x[k];
            int newJ = j + y[k];
            if (newI >= 0 && newJ >= 0 && newI < n && newJ < m &&
                grid[newI][newJ] == '1') {
                DFS(grid, visited, newI, newJ);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    count++;
                    DFS(grid, visited, i, j);
                }
            }
        }
        return count;
    }
};