// 261. Graph Valid Tree

class DSU { 
public:
    vector<int> parent;
    DSU(int n){
        parent.resize(n);
        for(int i = 0;i < n;i++){
            parent[i] = i;
        }
    }
    int findUParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }

    bool unite(int a, int b){
        int pa = findUParent(a);
        int pb = findUParent(b);

        if(pa == pb) return false;

        parent[b] = a;
        return true;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        if(edges.size() != n - 1) return false;

        for(auto i : edges){
            if(!dsu.unite(i[0],i[1])) return false;
        }

        return true;
    }
};
