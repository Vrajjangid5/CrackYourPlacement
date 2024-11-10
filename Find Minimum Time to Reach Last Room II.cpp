class Solution {
public:
    int di[4]={1,-1,0,0};
    int dj[4]={0,0,1,-1};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,pair<int,int>>>,vector<pair<int,pair<int,pair<int,int>>>>,greater<pair<int,pair<int,pair<int,int>>>>> pq;
        pq.push({0,{1,{0,0}}});
        while(!pq.empty()){
            auto topu=pq.top();
            int t=topu.first;
            int c=topu.second.first;
            int i=topu.second.second.first;
            int j=topu.second.second.second;
            pq.pop();
            for(int k=0;k<4;k++){
                int ni=i+di[k];
                int nj=j+dj[k];
                if(ni>=0 && nj>=0 && ni<n && nj<m && dist[ni][nj]>(c+max(t,moveTime[ni][nj]))){      
                    dist[ni][nj]=(c+max(t,moveTime[ni][nj]));
                    pq.push({dist[ni][nj],{c==1?2:1,{ni,nj}}});

                }
            }
        }
        return dist[n-1][m-1];
    }
};
