// Bellman–Ford
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        for (int i = 0; i <= k; i++) {

            vector<int> temp = dist;

            for (auto& f : flights) {
                int u = f[0]; // source city
                int v = f[1]; // destination city
                int w = f[2]; // flight cost

                if (dist[u] != INT_MAX && dist[u] + w < temp[v]) {
                    temp[v] = dist[u] + w;
                }
            }

            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

// Dijikstra Modified for k-stops but bellman is preferred
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // --------------------------------------------------
        // STEP 1: Build adjacency list
        // adj[u] = list of {v, w} meaning u -> v with cost w
        // --------------------------------------------------
        vector<vector<pair<int, int>>> adj(n);

        for (auto temp : flights) {
            int u = temp[0];
            int v = temp[1];
            int w = temp[2];
            adj[u].push_back({v, w});
        }

        // --------------------------------------------------
        // STEP 2: best[node][stops] = minimum cost to reach
        // 'node' using exactly 'stops' edges
        //
        // We allow at most (k + 1) edges because:
        // k stops = k + 1 flights
        // --------------------------------------------------
        vector<vector<int>> best(n, vector<int>(k + 2, INT_MAX));

        // Starting point: src with 0 cost and 0 stops
        best[src][0] = 0;

        // --------------------------------------------------
        // STEP 3: Min-heap (priority queue)
        // Each state = {cost_so_far, current_node, stops_used}
        // We always expand the cheapest state first
        // --------------------------------------------------
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        pq.push({0, src, 0});

        // --------------------------------------------------
        // STEP 4: Modified Dijkstra traversal
        // --------------------------------------------------
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int cost = curr[0];
            int u = curr[1];
            int stops = curr[2];

            // --------------------------------------------------
            // If destination is reached, this is the cheapest
            // possible cost (due to min-heap ordering)
            // --------------------------------------------------
            if (u == dst)
                return cost;

            // --------------------------------------------------
            // If stops exceed allowed limit, skip this path
            // --------------------------------------------------
            if (stops > k)
                continue;

            // --------------------------------------------------
            // Try to relax all outgoing edges from current node
            // --------------------------------------------------
            for (auto& [v, w] : adj[u]) {

                // If going to 'v' with one more stop gives
                // a cheaper cost, update and push to heap
                if (cost + w < best[v][stops + 1]) {
                    best[v][stops + 1] = cost + w;
                    pq.push({cost + w, v, stops + 1});
                }
            }
        }

        // --------------------------------------------------
        // If destination is never reached within k stops
        // --------------------------------------------------
        return -1;
    }
};
