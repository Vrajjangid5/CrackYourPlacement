class Solution {
public:

    int solve(vector<int>& p,vector<vector<int>>&dp,int ind,int buy){
        if(ind>=p.size()) return 0;

        if(dp[ind][buy]!=-1){
        return dp[ind][buy];
       }
       int profit=0;
        if(buy){
            int a=solve(p,dp,ind+1,0)-p[ind];
            int b=solve(p,dp,ind+1,1);
            profit=max(a,b);
        }else{
             int a=solve(p,dp,ind+1,1)+p[ind];
            int b=solve(p,dp,ind+1,0);
            profit=max(a,b);
        }
        return dp[ind][buy]=profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices,dp,0,1);
        
    }
};
