class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mp;
        for(auto &it:nums){
            mp[it]++;
        }
        vector<int> ans;
        int z=nums.size()/3;
        for(auto &it:mp){
            if(it.second>z){
                ans.push_back(it.first);
            }
            
        }
        return ans;
    }
};
