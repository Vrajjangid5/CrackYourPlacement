class Solution {
public:
    int WIDTH;
    int n;
    int solve(vector<vector<int>>& books,int remaningWt,int i,int Maxh,vector<vector<int>>& dp){
        if(i>=n){
            return Maxh;
        }
        int w=books[i][0];
        int h=books[i][1];
        if(dp[i][remaningWt]!=-1){
            return dp[i][remaningWt];
        }
        int keep=INT_MAX;
        int skip=INT_MAX;
        if(w<=remaningWt){
            keep=solve(books,remaningWt-w,i+1,max(Maxh,h),dp);
        }

        skip=Maxh+solve(books,WIDTH-w,i+1,h,dp);
        dp[i][remaningWt]=min(skip,keep);
        return dp[i][remaningWt];
    }


    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n=books.size();
        WIDTH=shelfWidth;
        int remaningWt=shelfWidth;
        vector<vector<int>>dp(1002,vector<int>(1002,-1));
        return solve(books,remaningWt,0,0,dp);
    }
};
