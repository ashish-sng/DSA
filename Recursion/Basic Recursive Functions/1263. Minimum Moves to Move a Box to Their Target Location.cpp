// 1263. Minimum Moves to Move a Box to Their Target Location

class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Directions: up, down, left, right
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        int sx, sy, bx, by, tx, ty;

        // Locate S, B, T
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (grid[i][j] == 'B') {
                    bx = i;
                    by = j;
                } else if (grid[i][j] == 'T') {
                    tx = i;
                    ty = j;
                }
            }
        }

        // visited[box_x][box_y][player_x][player_y]
        bool visited[20][20][20][20] = {};

        // 0-1 BFS queue: (pushes, box_x, box_y, player_x, player_y)
        deque<tuple<int, int, int, int, int>> dq;
        dq.push_front({0, bx, by, sx, sy});
        visited[bx][by][sx][sy] = true;

        while (!dq.empty()) {
            auto [pushes, bx, by, px, py] = dq.front();
            dq.pop_front();

            // If box reached target, done
            if (bx == tx && by == ty)
                return pushes;

            // Try pushing in all 4 directions
            for (int d = 0; d < 4; d++) {
                int nbx = bx + dx[d];
                int nby = by + dy[d];
                int need_px = bx - dx[d];
                int need_py = by - dy[d];

                // Check bounds
                if (!inBounds(nbx, nby, m, n) ||
                    !inBounds(need_px, need_py, m, n))
                    continue;

                // Box destination must be free
                if (grid[nbx][nby] == '#')
                    continue;

                // Player must be able to reach pushing position
                if (!canReach(px, py, need_px, need_py, bx, by, grid))
                    continue;

                if (!visited[nbx][nby][bx][by]) {
                    visited[nbx][nby][bx][by] = true;
                    dq.push_back({pushes + 1, nbx, nby, bx, by});
                }
            }
        }

        return -1;
    }

private:
    bool inBounds(int x, int y, int m, int n) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    // Can player reach (tx, ty) without crossing the box?
    bool canReach(int sx, int sy, int tx, int ty, int bx, int by,
                  vector<vector<char>>& grid) {

        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        bool seen[20][20] = {};

        q.push({sx, sy});
        seen[sx][sy] = true;

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == tx && y == ty)
                return true;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;
                if (seen[nx][ny])
                    continue;
                if (grid[nx][ny] == '#')
                    continue;
                if (nx == bx && ny == by)
                    continue; // box is a wall

                seen[nx][ny] = true;
                q.push({nx, ny});
            }
        }

        return false;
    }
};
