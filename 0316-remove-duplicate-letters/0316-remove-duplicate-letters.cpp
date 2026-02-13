class Solution {
public:
    string removeDuplicateLetters(string s) {
    int n=s.length();
    vector<int>freq(26,0);
    vector<bool>visited(26,0);
    // count frequency
    for(int i=0;i<n;i++){
    freq[s[i]-'a']++;
    }
    string temp="";
    for(int i=0;i<n;i++){
    freq[s[i]-'a']--;
    if(visited[s[i]-'a']){
    continue;
    }
    while(!temp.empty() && s[i]<temp.back() && freq[temp.back()-'a']>0){
    visited[temp.back()-'a']=0;
    temp.pop_back();
    }
    temp.push_back(s[i]);
    visited[s[i]-'a']=1;
    } 
    return temp;  
    }
};