// 685. Redundant Connection II

class DSU {
private:
    vector<int> parent;

public:
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    // returns false if union causes a cycle
    bool unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return false; // cycle detected

        parent[pv] = pu;
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        // Step 1: Track parent of each node
        vector<int> parent(n + 1, 0);

        // These will store the conflicting edges (if any)
        vector<int> edge1, edge2;

        // STEP 1: Detect "two parents"
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            if (parent[v] == 0) {
                parent[v] = u;
            } else {
                // Node v already has a parent → two parents case
                edge1 = {parent[v], v}; // old edge
                edge2 = {u, v};         // new edge (later one)
                // Mark this edge to be skipped later
                e[1] = 0;
            }
        }

        // STEP 2: DSU cycle detection
        DSU dsu(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            // Skip the second parent edge temporarily
            if (v == 0)
                continue;

            // If adding this edge creates a cycle
            if (!dsu.unite(u, v)) {
                // Case: cycle + two parents
                if (!edge1.empty())
                    return edge1;

                // Case: cycle only
                return {u, v};
            }
        }

        // STEP 3: No cycle found
        // Then the issue was only "two parents"
        return edge2;
    }
};