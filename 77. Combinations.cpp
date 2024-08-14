class Solution {
public:

    void solve(int i,int n,int k,vector<int>&ds,vector<vector<int>>&ans,vector<int>&nums){
        if(ds.size()==k){
            ans.push_back(ds);
            return;
        }
        if(i>=n){
            return;
        }
        ds.push_back(nums[i]);
        solve(i+1,n,k,ds,ans,nums);
        ds.pop_back();
        solve(i+1,n,k,ds,ans,nums);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>ds;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            nums[i]=i+1;
        }
        solve(0,n,k,ds,ans,nums);
        return ans;
    }
};
