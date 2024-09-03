class Solution {
public:

    int Solve(string s,int i,int j){
        int count=0;
        while(i>=0 and j<s.size() and s[i]==s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            int oddCount=Solve(s,i,i);
            count=count+oddCount;
            int evencount=Solve(s,i,i+1);
            count=count+evencount;
        }
        return count;
    }
};
