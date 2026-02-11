class Solution {
public:
    string removeDuplicateLetters(string s) {
    vector<int>freq(26,0);
    int n=s.length();
    for(int i=0;i<n;i++){
    freq[s[i]-'a']++;
    }
    string temp="";
    stack<char>st;
    vector<bool>visited(26,0);
    for(int i=0;i<n;i++){
    freq[s[i]-'a']--;
    if(visited[s[i]-'a']){
    continue;
    }
    while(!st.empty() && st.top()>s[i] && freq[st.top()-'a']>0){
    
    visited[st.top()-'a']=0;
    st.pop();
    }
    st.push(s[i]);
    visited[s[i]-'a']=1;
    }
    while(!st.empty()){
    temp+=st.top();
    st.pop();
    }
    reverse(temp.begin(), temp.end());
    return temp;    
    }
};