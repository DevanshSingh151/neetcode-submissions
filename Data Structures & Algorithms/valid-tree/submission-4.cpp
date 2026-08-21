class Solution {
public:
    bool bfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& parent) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while (!q.empty()) {
            int f = q.front();
            q.pop();

            for (int nbr : adj[f]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = 1;
                    parent[nbr] = f;
                } else {
                    if (parent[f] != nbr) {
                        return true;    // Cycle found
                    }
                }
            }
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        if (edges.size() != n - 1)
            return false;
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> visited(n, 0), parent(n, -1);

        
        bool ans = bfs(0, adj, visited, parent);

        if (ans)
            return false;
        // Check whether every node was visited
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                return false;
        }
        return true;
    }
};