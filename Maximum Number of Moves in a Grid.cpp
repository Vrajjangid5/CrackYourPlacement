class Solution {
public:
    bool issafe(int i ,int j ,int row ,int clm,vector<vector<int>>& grid,int prev){

        if( i >= 0 && j >= 0 && i < row && j < clm && grid[i][j] > prev) return true;
        
        return false;
}
     int solve(vector<vector<int>>& grid,int i , int j , int row ,int clm,int prev, vector<vector<int>>&dp){
         if( i >= row || j >= clm ) return 0;
         
         int ans1  = 0, ans2 = 0,ans3 = 0; 
        
         if(dp[i][j] != -1) return dp[i][j];

         if(issafe(i-1,j+1,row,clm,grid,prev)) ans1 = 1 + solve(grid,i-1,j+1,row,clm,grid[i-1][j+1],dp);
         
         if(issafe(i,j+1,row,clm,grid,prev)) ans2 = 1 + solve(grid,i,j+1,row,clm,grid[i][j+1],dp);
         
         if(issafe(i+1,j+1,row,clm,grid,prev))  ans3 = 1 + solve(grid,i+1,j+1,row,clm,grid[i+1][j+1],dp);
         
         return dp[i][j] = max(ans1,max(ans2,ans3));
     }
    int maxMoves(vector<vector<int>>& grid) {
        int row = grid.size();
        int clm = grid[0].size();

        vector<vector<int>>dp(row,vector<int>(clm,-1));
        
        for(int i = 0 ;i<clm;i++){
            int maxi = INT_MIN;
            for(int j = 0 ; j<row;j++) maxi = max(solve(grid,j,i,row,clm,grid[j][i],dp),maxi);
            return maxi;
        }
        return 0;
    }
};
