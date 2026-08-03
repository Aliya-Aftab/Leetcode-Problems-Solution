class Solution {
public:
    void solve(string &s){
        char ch = s[0];
        for(int i=1; i<s.length(); i++){
            s[i-1]=s[i];
        }
        s[s.length()-1]=ch;
    }
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()){
            return false;
        }
        if(s==goal){
            return true;
        }
        for(int i=0; i<s.length(); i++){
            solve(s);
            if(s==goal){
                return true;
            }
        }
        return false;
    }
};