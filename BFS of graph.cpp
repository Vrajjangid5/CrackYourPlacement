 // Function to return Breadth First Traversal of given graph.
    void solve(vector<vector<int>> &adj,int src,unordered_map<int,bool> &visit,vector<int>&ans){
        visit[src]=true;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int fNode=q.front();
            q.pop();
            ans.push_back(fNode);
            for(auto nbr:adj[fNode]){
                if(!visit[nbr]){
                    q.push(nbr);
                    visit[nbr]=true;
                }
            }
        }
    }
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        unordered_map<int,bool> visit(adj.size(),false);
        int sorce=0;
        vector<int>ans;
        solve(adj,sorce,visit,ans);
        return ans;
        
    }
