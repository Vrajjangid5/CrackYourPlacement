class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int> first;
        vector<int>second;
        for(vector<int>&interval:intervals){
            first.push_back(interval[0]);
            second.push_back(interval[1]);
        }
        sort(first.begin(),first.end());
        sort(second.begin(),second.end());
        int ans=1;
        int intervel=1;
        int i=1;
        int j=0;
        while(i<n and j<n){
            if(first[i]<=second[j]){
                i++;
                intervel++;
            }else{
                j++;
                intervel--;
            }

            ans= max(ans,intervel);
        }
        return ans;
    }
};
