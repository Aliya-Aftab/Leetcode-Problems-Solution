class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
    unordered_set<string>st(deadends.begin(), deadends.end());
    string start="0000";
    queue<string>q;
    q.push(start);
    int level=0;
    if(st.find(start)!=st.end()){
    return -1;
    }
    while(!q.empty()){
    int size=q.size();
    while(size--){
    string curr=q.front();
    q.pop();
    if(curr==target){
    return level;
    }
    for(int i=0;i<4;i++){
    char temp=curr[i];
    char dec=temp=='0' ? '9' : temp-1;
    char inc=temp=='9' ? '0' : temp+1;
    
    curr[i]=dec;
    if(st.find(curr)==st.end()){
    st.insert(curr);
    q.push(curr);
    }
    curr[i]=inc;
    if(st.find(curr)==st.end()){
    st.insert(curr);
    q.push(curr);
    }
    curr[i]=temp;
    }
    }
    level++;
    }
    return -1;
    }
};