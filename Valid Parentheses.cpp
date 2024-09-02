bool isValidParenthesis(string s)
{
    // Write your code here.'
    stack<char>st;
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        if(ch=='{'||ch=='[' ||ch=='('){
            st.push(s[i]);
        }else if(!st.empty()){
            if ((s[i] == '}' and st.top()=='{') and !st.empty()) {
            st.pop();
        }
        if ((s[i] == ']' and st.top()=='[') and !st.empty()) {
            st.pop();
        }
        if ((s[i] == ')' and st.top()=='(') and !st.empty()) {
            st.pop();
        }
        }
        else{
            return 0;
        }
    }
    return st.empty();
}
