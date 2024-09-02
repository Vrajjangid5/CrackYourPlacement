class Solution {
public:

    bool isVowel(char ch){
            ch=tolower(ch);
            return (ch=='a'|| ch=='e' || ch=='i'|| ch=='o' || ch=='u');
    }

    string reverseVowels(string s) {
        int i=0;
        int j=s.size();
        while(i<j){
            if(isVowel(s[i]) and isVowel(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }else if(isVowel(s[i])==0){
                i++;
            }else{
                j--;
            }
        }
        return s;
    }
};
