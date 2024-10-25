class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        vector<int>ans(N,0);
                int last=-1,cnt=0;
                priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
                for(int i=0;i<N;i++){
                    pq.push({arr[i],i});
                }
                while(!pq.empty()){
                    int temp=pq.top().first;
                    int id=pq.top().second;
                    pq.pop();
                    if(temp>last){
                        cnt++;
                        ans[id]=cnt;
                        last=temp;
                    }
                    else if(temp==last)
                    ans[id]=cnt;
                }
                return ans;

    }

};
