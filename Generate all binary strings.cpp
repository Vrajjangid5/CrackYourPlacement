 void solve(int n,string curr,vector<string>&ans){
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        if(curr.empty()||curr.back()=='0'){
            solve(n,curr+'0',ans);
            solve(n,curr+'1',ans);
        }
        if(curr.back()=='1'){
            solve(n,curr+'0',ans);
        }
    }


    vector<string> generateBinaryStrings(int num){
        //Write your code
        vector<string>ans;
        string st="";
        solve(num,st,ans);
        return ans;
    }
