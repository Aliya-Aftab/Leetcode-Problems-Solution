class Solution {
public:
    string removeDuplicateLetters(string s) {
    string temp="";
    vector<bool>visited(26,0);
    vector<int>freq(26,0);
    int n=s.length();
    for(int i=0;i<n;i++){
    freq[s[i]-'a']++;
    }
    for(int i=0;i<n;i++){
freq[s[i]-'a']--;
   if( visited[s[i]-'a']){
   continue;
   }
   
   while(!temp.empty() && temp.back()>s[i] && freq[temp.back()-'a']>0){
   visited[temp.back()-'a']=0;
   temp.pop_back();
   }
   temp.push_back(s[i]);
   visited[s[i]-'a']=1;
    } 
    return temp;   
    }
};