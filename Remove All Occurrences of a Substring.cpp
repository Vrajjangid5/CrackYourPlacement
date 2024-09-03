class Solution {
public:
    string removeOccurrences(string s, string part) {
        int findOp=s.find(part);
        while(findOp!=string::npos){
            s.erase(findOp,part.length());
            findOp=s.find(part);
        }
        return s;
    }
};
