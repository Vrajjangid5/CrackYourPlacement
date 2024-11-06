void solve(vector<int> &ans,int src,  unordered_map<int,bool> &visit,vector<vector<int>>& adj){
        ans.push_back(src);
        visit[src]=true;
        for(auto nbr:adj[src]){
            if(!visit[nbr]){
                solve(ans,nbr,visit,adj);
            }
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        unordered_map<int,bool> visit;
        int src=0;
        vector<int> ans;
        solve(ans,src,visit,adj);
        return ans;
    }
