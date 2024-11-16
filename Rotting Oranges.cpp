class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        vector<vector<int>>adj=grid;
        queue<pair<pair<int,int>,int>>q;
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(adj[i][j]==2){
                    q.push({{i,j},0});
                }
                
            }
        }
      

        int tm=0;
      int dx[]={-1,0,1,0};
      int dy[]={0,1,0,-1};
        while(!q.empty()){
           int x=q.front().first.first;
           int y=q.front().first.second;
           int t=q.front().second;
           q.pop();
           tm=max(t,tm);
           for(int i=0;i<4;i++){
            int newX=x+dx[i];
            int newY=y+dy[i];
            if(newX>=0 and newX<adj.size() and newY>=0 and newY<adj[0].size() and
                adj[newX][newY]!=2 and adj[newX][newY]==1
            ){
                q.push({{newX,newY},t+1});
                adj[newX][newY]=2;
            }
           }
        }
          for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(adj[i][j]==1){
                  return -1;
                }
                
            }
        }
        return tm;

    }
};
