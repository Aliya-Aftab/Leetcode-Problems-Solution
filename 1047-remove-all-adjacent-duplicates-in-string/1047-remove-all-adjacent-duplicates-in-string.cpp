class Solution {
public:
    string removeDuplicates(string s) {
    int n=s.length();
    stack<char>st;
    for(int i=0;i<n;i++){
    if(!st.empty() && st.top()==s[i]){
    st.pop();
    }
    else{
    st.push(s[i]);
    }
    }
    string temp="";
    while(!st.empty()){
    temp+=st.top();
    st.pop();
    }
    reverse(temp.begin(), temp.end());
    return temp;  
    }
};