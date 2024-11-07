bool solve(vector<vector<int>>& adj, int src, unordered_map<int, bool>& visit, int parent) {
    visit[src] = true;
    
    for (auto neighbor : adj[src]) {
        if (!visit[neighbor]) {
            bool check = solve(adj, neighbor, visit, src);
            if (check) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;
        }
    }
    
    return false;
}
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
          unordered_map<int, bool> visit;
    
    for (int i = 0; i < adj.size(); ++i) {
        if (!visit[i]) {
            if (solve(adj, i, visit, -1)) {
                return true;
            }
        }
    }
    
    return false;
        
    }
