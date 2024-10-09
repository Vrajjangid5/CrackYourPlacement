class Solution {
public:
 
int find(int i,int buy,vector<int>&a,int k,vector<vector<vector<int>>>&dp){
     if(k==0 || i==a.size()){
        return 0;
     }
    if(dp[i][buy][k]!=-1){
        return dp[i][buy][k];
    }
    if(buy==1){
        int take=-a[i]+find(i+1,0,a,k,dp);
        int notke=find(i+1,1,a,k,dp);
        
        dp[i][buy][k]=max(take,notke);
    }
    
    else{
        int sell=a[i]+find(i+1,1,a,k-1,dp);
        int notsell=find(i+1,0,a,k,dp);
        
         dp[i][buy][k]=max(sell,notsell);
    }
    return dp[i][buy][k];

}
    int maxProfit(int k, vector<int>& A) {
    int buy=1;
    vector<int>a=A;
    // int k=2;
        vector<vector<vector<int>>> dp(a.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));
  
    return max(0,find(0,buy,a,k,dp));


    }
};
