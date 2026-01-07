class Solution {
public:
    bool isDigit(char ch){
    return ch>=48 && ch<=57;
    }
    
    void generate(string &s, int n,int idx ,string &temp, vector<string>&ans){
    if(idx==n){
    ans.push_back(temp);
    return;
    }
    if(isDigit(s[idx])){
    temp.push_back(s[idx]);
    generate(s,n,idx+1,temp,ans);
    temp.pop_back();    
    }
    else{
    temp.push_back(s[idx]);
    generate(s,n,idx+1,temp,ans);
    temp.pop_back();
    temp.push_back(s[idx]^32);
    generate(s,n,idx+1,temp,ans);
    temp.pop_back();
    }
    }
    vector<string> letterCasePermutation(string s) {
    int n=s.length() ;
    string temp;
    vector<string>ans;
    generate(s,n,0,temp,ans);
    return ans;
    }
};