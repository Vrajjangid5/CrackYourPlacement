class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        ans.push_back(s[0]);
        for(int i=1;i<s.size();i++){
            if(ans.size()>0 and (ans[ans.size()-1]==s[i])){
                ans.pop_back();
            }else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
