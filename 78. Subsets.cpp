class Solution {
public:

    void solve(int i,vector<int>num,vector<int>&nums,vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(num);
            return;
        }
        num.push_back(nums[i]);
        solve(i+1,num,nums,ans);
        num.pop_back();
        solve(i+1,num,nums,ans);
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        
        vector<int>num;
        // ans.push_back(num);
        solve(0,num,nums,ans);
        return ans;
    }
};
