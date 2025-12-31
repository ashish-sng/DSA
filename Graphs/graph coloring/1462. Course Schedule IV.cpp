// 1462. Course Schedule IV
// TOPO OSRT + DP
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto& p : prerequisites) {
            adj[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<vector<bool>> isPrereq(numCourses, vector<bool>(numCourses, false));

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto v : adj[u]) {
                isPrereq[u][v] = true;

                // All prerequisites of u are also prerequisites of v
                for (int k = 0; k < numCourses; k++) {
                    if (isPrereq[k][u]) {
                        isPrereq[k][v] = true;
                    }
                }

                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        vector<bool> answer;
        for (auto& qy : queries) {
            answer.push_back(isPrereq[qy[0]][qy[1]]);
        }

        return answer;
    }
};

// Floyd Warshall
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));

        for (auto& p : prerequisites) {
            reachable[p[0]][p[1]] = true;
        }

        for (int k = 0; k < numCourses; k++) {
            for (int u = 0; u < numCourses; u++) {
                for (int v = 0; v < numCourses; v++) {
                    if (reachable[u][k] && reachable[k][v]) {
                        reachable[u][v] = true;
                    }
                }
            }
        }

        vector<bool> answer;
        for (auto& q : queries) {
            answer.push_back(reachable[q[0]][q[1]]);
        }

        return answer;
    }
};

