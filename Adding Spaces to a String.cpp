class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int j=0;
        int si=spaces.size();
        for(int i=0;i<s.size();i++){
            if(i==spaces[j]){
                ans+=" ";
                if(j+1<si){
                    j++;
                }
            }
            ans+=s[i];
        }
        return ans;
    }
};
