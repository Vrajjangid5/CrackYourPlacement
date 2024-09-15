class Solution {
public:

    static bool compare(int a,int b){
        return to_string(a)+to_string(b)>to_string(b)+to_string(a);
    }

    string largestNumber(vector<int>& nums) {
        string ans="";
        
        
        sort(nums.begin(),nums.end(),compare);
        for(int i=0;i<nums.size();i++){
            ans+=to_string(nums[i]);
            if(ans[0]=='0') return "0";
        }
        return ans;
    }
};
