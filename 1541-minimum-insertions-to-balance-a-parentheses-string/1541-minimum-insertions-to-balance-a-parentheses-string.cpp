class Solution {
public:
    int minInsertions(string s) {
    int n=s.length();
    int open=0, needed=0;
    for(int i=0;i<n;i++){
    if(s[i]=='('){
    open++;
    }
    else{
    // two cons closing
    if(i+1< n && s[i+1]==')'){
    i++;
    }
    else{
    needed++;
    }
    if(open>0){
    open--;
    }
    else{
    needed++;
    }
    }
    }
    return needed + 2*open;    
    }
};