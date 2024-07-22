class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int,int>mp;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // int maxi=0;
        // int ans=0;
        // for(auto &p:mp){
        //     int k=p.second;
        //     if(maxi<k){
        //         maxi=k;
        //         ans=p.first;
        //     }
        // }
        // return ans;
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};
