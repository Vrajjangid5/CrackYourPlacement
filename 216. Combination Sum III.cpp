class Solution {
public:

    void solve(int i,vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans,int k,int n,int curr){
        if(ds.size()==k and curr==n){
            ans.push_back(ds);
            return;
        }
        if (i >= 9 || curr > n || ds.size() > k) {
            return;
        }
      //  curr+=arr[i];
        ds.push_back(arr[i]);
        solve(i+1,arr,ds,ans,k,n,curr+arr[i]);
      //  curr-=arr[i];
        ds.pop_back();
        solve(i+1,arr,ds,ans,k,n,curr);
    }


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        vector<int>arr(9);
        for(int i=0;i<9;i++){
            arr[i]=i+1;
        }
        solve(0,arr,ds,ans,k,n,0);
        return ans;
    }
};
