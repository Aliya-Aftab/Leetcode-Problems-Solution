class Solution {
public:
    bool isValid(string s) {
    int n=s.length();
    stack<char>st;
    for(int i=0;i<n;i++){
    if(s[i]=='a' || s[i]=='b'){
    st.push(s[i]);
    }
    else{
    if(st.empty()){
    return false;
    }
    if(st.top()=='b'){
    st.pop();
    if(st.empty() || st.top()!='a'){
    return false;
    }
    st.pop();
    }
    else{
    return false;
    }
    }
    }
    return st.empty();   
    }
};