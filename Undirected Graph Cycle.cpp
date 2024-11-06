bool solve(vector<vector<int>>& adj,int src,unordered_map<int,bool> &mp){
        unordered_map<int,int>parent;
        queue<int> q;
        q.push(src);
        mp[src]=true;
        parent[src]=-1;
        while(!q.empty()){
            int srcNode=q.front();
            q.pop();
            for(auto nbr:adj[srcNode]){
                if(!mp[nbr]){
                    q.push(nbr);
                    mp[nbr]=true;
                    parent[nbr]=srcNode;
                }else{
                    if(nbr!=parent[srcNode]){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        // Code herere
        int src=0;
        unordered_map<int,bool> mp;
        return solve(adj,src,mp);
    }
