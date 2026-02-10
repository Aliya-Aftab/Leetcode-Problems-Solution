class Solution {
public:
    int minAddToMakeValid(string s) {
    int n=s.length();
    int open=0, needed=0;
    for(int i=0;i<n;i++){
    if(s[i]=='('){
    open++;
    }
    else{
    if(open>0){
    open--;
    }
    else{
    needed++;
    }
    }
    }
    return open+needed;    
    }
};