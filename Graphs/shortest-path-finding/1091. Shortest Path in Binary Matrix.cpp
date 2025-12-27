// 1091. Shortest Path in Binary Matrix

class Solution {
public:
    int directions[8][2] = {{1, 0}, {0, 1},   {-1, 0}, {0, -1},
                            {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rs = grid.size();
        int cs = grid[0].size();

        if (grid[0][0] == 1 || grid[rs - 1][cs - 1] == 1)
            return -1;

        int pathLength = 1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int irc = q.front().first;
                int icc = q.front().second;
                q.pop();

                if (irc == rs - 1 && icc == cs - 1)
                    return pathLength;

                for (auto i : directions) {
                    int nrc = irc + i[0];
                    int ncc = icc + i[1];

                    if (nrc >= 0 && nrc < rs && ncc >= 0 && ncc < cs &&
                        grid[nrc][ncc] == 0) {
                        grid[nrc][ncc] = 1;
                        q.push({nrc, ncc});
                    }
                }
            }
            pathLength++;
        }
        return -1;
    }
};