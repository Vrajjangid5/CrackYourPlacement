class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        vector<int>chair(n,-1);
        int ans=0;
        int arivalTime=times[targetFriend][0];
        sort(begin(times),end(times));
        for(vector<int>&time:times){
            int depart=time[1];
            int arivel=time[0];
            for(int i=0;i<n;i++){
                if(chair[i]<=arivel){
                    chair[i]=depart;
                    if(arivel==arivalTime){
                        return i;
                    }
                    break;
                }
            }
           
        }
        return 0;
    }
};
