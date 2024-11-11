class Solution {
public:

    void dfs(map<pair<int,int>,bool> &v,int i,int j,vector<vector<char>>& grid){
        queue<pair<int,int>>q;
        q.push({i,j});
        v[{i,j}]=true;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int newX=row+dx[i];
                int newY=col+dy[i];
                if(newX>=0 and newX<grid.size() and newY>=0 and newY<grid.size() and !v[{newX,newY}] and grid[newX][newY]=='1'){
                    q.push({newX,newY});
                    v[{newX,newY}]=true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
       map<pair<int,int>,bool> v;
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!v[{i,j}] and grid[i][j]=='1'){
                    dfs(v,i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};
