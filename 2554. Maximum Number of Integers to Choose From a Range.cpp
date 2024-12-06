class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<banned.size();i++){
            mp[banned[i]]++;
        }
        int sum=0;
        for(int i=1;i<=n;i++){
           
            if((sum+i)<=maxSum){
                if(mp.find(i)==mp.end()){
                    ans++;
                     sum+=i;
                }
            }else if(sum>=maxSum){
                break;
            }
        }
        return ans;
        
        
    }
};
