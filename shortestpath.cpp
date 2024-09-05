class Solution {
public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N, int src) {
        vector<vector<int>> adj(N);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> path(N, -1);
        vector<bool> visited(N, false);
        
        queue<pair<int, int>> q;
        q.push({src, 0});
        visited[src] = true;
        
        while (!q.empty()) {
            int node = q.front().first;
            int weight = q.front().second;
            path[node] = weight;
            q.pop();
            
            for (int i = 0; i < adj[node].size(); i++) {
                if (!visited[adj[node][i]]) {
                    visited[adj[node][i]] = true;
                    q.push({adj[node][i], weight + 1});
                }
            }
        }
        
        return path;
    }
};