class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, stack<int> &ans) {
        
        vis[node] = true;
        
        for(auto neighbor : adj[node]) {
            if(!vis[neighbor]) dfs(neighbor, adj, vis, ans);
        }
        ans.push(node);
        
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        
        int n = adj.size();
        vector<bool> vis(n, false);
        stack<int> ans;
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) dfs(i, adj, vis, ans);
        }
        vector<int> res;
        while(!ans.empty()) {
            int x = ans.top(); ans.pop();
            res.push_back(x);
        }
        return res;
    }
};
