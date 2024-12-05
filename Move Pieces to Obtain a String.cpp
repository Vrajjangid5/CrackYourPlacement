class Solution {
public:
    bool canChange(string s, string s2) {
      int n=s.size();
      int n2=s2.size();
      int i=0;
      int j=0;
      while(i<n||j<n2){
        while(i<n and s[i]=='_'){
            i++;
        }
        while(j<n and s2[j]=='_'){
            j++;
        }
        if(s[i]!=s2[j]){
            return false;
        }
        if(i==n || j==n){
            break;
        }
        if(s[i]=='R'){
            if(i>j){
                return false;
            }
        }
        if(s2[j]=='L'){
            if(i<j){
                return false;
            }
        }
        i++;
        j++;
      }
      return i==j;
    }
};
