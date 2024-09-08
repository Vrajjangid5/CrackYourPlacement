
int solve(int i,vector<int> &arr,vector<int> &dp){
    if(i>=arr.size()-1){
        return 0;

    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int ans=1e5;

    for(int k=1;k<=arr[i];k++){
        ans=min(ans,1+solve(i+k, arr, dp));
    }
    return dp[i]=ans;
}

int minJumps(vector<int> &arr,int n) 
{
    // Write your code here.

     vector<int>dp(arr.size(),-1);
     int ans=solve(0,arr,dp);
     return ans==1e5?-1:ans;


}
