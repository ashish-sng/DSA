// 210. Course Schedule II
// Topological sort --> Kahn's algorithm
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto edge : prerequisites) {
            int course = edge[0];
            int prerequisite = edge[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (int next : adj[node]) {
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        if (topo.size() == numCourses) {
            return topo;
        }

        return vector<int>();
    }
};