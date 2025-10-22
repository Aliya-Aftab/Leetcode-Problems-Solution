class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
    unordered_set<string>st(bank.begin(), bank.end());
    queue<pair<string, int>>q;
    vector<char>givenCh(4);
    givenCh[0]='A';
    givenCh[1]='C';
    givenCh[2]='G';
    givenCh[3]='T';
    if(st.find(endGene)==st.end()){
    return -1;
    }
    q.push({startGene,0});
    while(!q.empty()){
    string curr=q.front().first;
    int steps=q.front().second;
    q.pop();
    if(curr==endGene){
    return steps;
    }
    for(int i=0;i<8;i++){
    char temp=curr[i];
    for(int j=0;j<4;j++){
    curr[i]=givenCh[j];
    if(st.find(curr)!=st.end()){
    st.erase(curr);
    q.push({curr, steps+1});
    }
    }
    curr[i]=temp;
    }
    }
    return -1;
    }
};