class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int k=0;
        for(auto &i:mp){
            int m=i.second;
            if(m>=2){
                k=i.first;
                break;
            }
        }
        return k;
    }
};
// 287. Find the Duplicate Number
//there are many app. to solve this question like binary search slow fast
