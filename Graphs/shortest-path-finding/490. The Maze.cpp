// 490. The Maze

class Solution {
public:
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int rs = maze.size();
        int cs = maze[0].size();
        vector<vector<bool>> visited(rs, vector<bool>(cs, false));

        if(maze[start[0]][start[1]] == 1 || maze[destination[0]][destination[1]] == 1) return false;

        queue<pair<int, int>> q;

        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = true;

        while(!q.empty()){
            int irc = q.front().first; // irc -> initial row coordinate
            int icc = q.front().second;
            q.pop();

            if(irc == destination[0] && icc == destination[1]) return true;

            for(auto d : directions){
                int nrc = irc;
                int ncc = icc;

                while (nrc + d[0] >= 0 && nrc + d[0] < rs &&
                    ncc + d[1] >= 0 && ncc + d[1] < cs &&
                    maze[nrc + d[0]][ncc + d[1]] == 0) {
                    nrc += d[0];
                    ncc += d[1];
                }
                // If this stopping position is not visited
                if (!visited[nrc][ncc]) {
                    visited[nrc][ncc] = true;
                    q.push({nrc, ncc});
                }
            }
        }

        return false;
    }
};
