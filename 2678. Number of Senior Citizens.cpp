class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(auto &ch:details){
            if(ch[11]=='7' || ch[11]=='8' || ch[11]=='9' || (ch[11]=='6' and ch[12]!='0')){
                count++;
            } 
        }
        return count;
    }
};
