#include <bits/stdc++.h> 

int solve(string &str1,string &str2,int i,int j ,vector<vector<int>>&dp){
  if(i>=str1.size() || j>=str2.size()){
    return 0;
  }
  if(dp[i][j]!=-1){
    return dp[i][j];
  }
  if(str1[i]==str2[j]){
    return dp[i][j]= 1+solve(str1,str2,i+1,j+1,dp);
  }else{
  return dp[i][j]=max( solve(str1,str2,i+1,j,dp),solve(str1,str2,i,j+1,dp));
  }

}

int getLengthOfLCS(string & str1, string & str2) {
  // Write your code here.
  vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1,-1));
  int ans=solve(str1,str2,0,0,dp);
  return ans;
}
