class Solution {
public:
    int minMoves(vector<int>& nums) {
        // int mini=INT_MAX;
        // for(int n:nums){
        //     if(mini>n){
        //         mini=n;
        //     }

        // }
        sort(nums.begin(),nums.end());
        int mini = nums[0];
        int ans=0;
        for(int n:nums){
            ans+=(n-mini);
        }
        return ans;
    }
};
