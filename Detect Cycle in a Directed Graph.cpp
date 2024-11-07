 bool solve(vector<vector<int>>& adj, int src, unordered_map<int, bool>& visit, unordered_map<int, bool> dfs) {
      visit[src] = true;
    dfs[src] = true;
    
    for (auto neighbor : adj[src]) {
        if (!visit[neighbor]) {
            if (solve(adj, neighbor, visit, dfs)) {
                return true;
            }
        } else if (dfs[neighbor]) {  // A cycle is detected
            return true;
        }
    }
    
    dfs[src] = false;  // Backtrack
    return false;
}
    
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        unordered_map<int, bool> visit;
          unordered_map<int, bool> dfs;
    
    for (int i = 0; i < V; ++i) {
        if (!visit[i]) {
            if (solve(adj, i, visit, dfs)) {
                return true;
            }
        }
    }
    
    return false;
    }
