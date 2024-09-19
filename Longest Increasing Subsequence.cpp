class Solution {
public:
    int solveAns(vector<int>& nums,int curr,int prev, vector<vector<int>>&dp){
        if(curr>=nums.size()){
            return 0;

        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        //include case
        int include=0;
        if(prev==-1 || nums[curr]>nums[prev])
            include=1+solveAns(nums,curr+1,curr,dp);
        
        //exclude
        int exclude=0+solveAns(nums,curr+1,prev,dp);

        dp[curr][prev+1]=max(include,exclude);
        return dp[curr][prev+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        int curr=0;
        int prev=-1;
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int ans= solveAns(nums,curr,prev,dp);
        return ans;
    }
};
