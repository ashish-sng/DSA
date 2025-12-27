// Dijkstra's Algorithm

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // -----------------------------
        // Step 1: Build adjacency list
        // -----------------------------
        // graph[u] = {v, w} → edge u -> v with weight w
        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto& t : times) {
            int u = t[0];
            int v = t[1];
            int w = t[2];
            graph[u].push_back({v, w});
        }

        // -----------------------------
        // Step 2: Distance array
        // -----------------------------
        // dist[i] = shortest time to reach node i from k
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // -----------------------------
        // Step 3: Min-heap (distance, node)
        // -----------------------------
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, k});

        // -----------------------------
        // Step 4: Dijkstra's Algorithm
        // -----------------------------
        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            // Skip outdated entry
            if (currDist > dist[node])
                continue;

            for (auto& [next, weight] : graph[node]) {
                if (dist[node] + weight < dist[next]) {
                    dist[next] = dist[node] + weight;
                    pq.push({dist[next], next});
                }
            }
        }

        // -----------------------------
        // Step 5: Find maximum distance
        // -----------------------------
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1; // unreachable node
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};