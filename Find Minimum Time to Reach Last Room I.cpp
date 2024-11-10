class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        ans[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int value=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            int dx[]={0,-1,0,1};
            int dy[]={-1,0,1,0};
            for(int i=0;i<4;i++){
                int newX=row+dx[i];
                int newY=col+dy[i];
                if(newX>=0 and newX<n and newY>=0 and newY<m){
                    int diff=max(value,moveTime[newX][newY])+1;
                    if(diff<ans[newX][newY]){
                        ans[newX][newY]=diff;
                        pq.push({diff,{newX,newY}});
                    }
                }
            }
            
        }
        return ans[n-1][m-1];
    }
};
