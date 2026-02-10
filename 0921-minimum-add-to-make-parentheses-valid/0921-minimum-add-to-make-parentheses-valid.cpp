class Solution {
public:
    int minAddToMakeValid(string s) {
    int n=s.length();
    stack<char>st;
    int count=0;
    for(int i=0;i<n;i++){
    if(s[i]=='('){
    st.push(s[i]);
    }
    else{ // closing bracket
    if(!st.empty() && st.top()=='('){
    st.pop();
    }
    else{
    count++;
    }
    }
    }
    while(!st.empty()){
    count++;
    st.pop();
    } 
    return count;   
    }
};