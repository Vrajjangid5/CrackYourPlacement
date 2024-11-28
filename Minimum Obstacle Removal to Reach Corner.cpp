class Solution {
public:
 bool isValid(int row, int col, int n, int m){
        
        if(row < 0 || row >= n || col < 0 || col >= m){
            return false;
        }

        return true;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;

        dist[0][0]=grid[0][0];
        p.push({grid[0][0],{0,0}});
        while(!p.empty()){
            int step=p.top().first;
            int row=p.top().second.first;
            int col=p.top().second.second;
            p.pop();
            if(row==n-1 and col==m-1){
                return step;
            }
           int dx[]={0,0,1,-1};
           int dy[]={1,-1,0,0};
            for(int i=0;i<4;i++){
                int x=row+dx[i];
                int y=col+dy[i];
                if(isValid(x,y,n,m) and dist[x][y]>step+grid[x][y]){
                    dist[x][y]=step+grid[x][y];
                    p.push({dist[x][y],{x,y}});
                }
            }
        }
        
        return -1;
    }
};
