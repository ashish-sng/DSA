// 802. Find Eventual Safe States

// Reverse graph + Kahn (Topo-style)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> outdegree(n, 0);

        for (int u = 0; u < n; u++) {
            outdegree[u] = graph[u].size();
            for (int v : graph[u]) {
                revGraph[v].push_back(u);
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0)
                q.push(i);
        }

        vector<bool> safe(n, false);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;

            for (int prev : revGraph[node]) {
                outdegree[prev]--;
                if (outdegree[prev] == 0) {
                    q.push(prev);
                }
            }
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (safe[i])
                result.push_back(i);
        }

        return result;
    }
};

// DFS + coloring (3-state)
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& state){
        if(state[node] == 1) return false;
        if(state[node] == 2) return true;

        state[node] = 1;
        for(int next : graph[node]){
            if(!dfs(next, graph, state)) return false;
        }

        state[node] = 2;
        return true;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);

        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, state))
                result.push_back(i);
        }

        return result;
    }
};