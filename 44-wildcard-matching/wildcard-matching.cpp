class Solution {
public: 
    int t[2001][2001];
    bool solve(int i, int j, string &s, string &p){
        if(i==s.length() && j==p.length()){
            return true;
        }
        if(j==p.length()){
            return false;
        }
        if(i == s.length()){
        for(int k=j; k<p.length(); k++){
        if(p[k]!='*'){
        return false;
        }
        }
        return true;
    } 
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(s[i]==p[j] || p[j]=='?'){
            return t[i][j]= solve(i+1, j+1, s, p);
        }
        else if(p[j]=='*'){
            return t[i][j]=solve(i, j+1, s, p) || solve(i+1, j, s, p);
        }
        else {
            return t[i][j]= false;
        }
    }
    bool isMatch(string s, string p) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, s, p);
    }
};