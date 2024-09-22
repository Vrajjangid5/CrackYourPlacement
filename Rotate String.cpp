class Solution {
public:
    bool rotateString(string s, string goal) {
         if (s.length() == 1) {
            return true ;
        }
        if (s.length() != goal.length()) {
            return false ;
        }
        goal=goal+goal;
        if(goal.find(s)==string::npos){
            return false;
        }
        return true;
    }
};
