class Solution {
public:
    int dp[21][21];
    bool solve(int i, int j, string s, string p){
        if(j==p.length()){
            return i==s.length();
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool ans=false;
        bool firstChMatched=( i<s.length() && (p[j]==s[i] || p[j]=='.'));
        if(j+1 < p.length() && p[j+1]=='*'){
            ans = (solve(i,j+2, s, p) || (firstChMatched && solve(i+1, j, s, p)));
        }
        else{
            ans = firstChMatched && solve(i+1, j+1, s, p);
        }
        return dp[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(0,0,s,p);
    }
};