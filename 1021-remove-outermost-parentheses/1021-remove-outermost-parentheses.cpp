class Solution {
public:
    string removeOuterParentheses(string s) {
    int n=s.length();
    int open=0;
    string res="";
    string temp="";
    for(int i=0;i<n;i++){
    if(open==0 && !temp.empty()){
    res+=temp.substr(1, temp.length()-2);
    temp.clear();
    }
    if(s[i]=='('){
    temp+="(";
    open++;
    }
    else{
    temp+=")";
    open--;
    }
    }
    if(!temp.empty()){
    res+=temp.substr(1, temp.length()-2);
    } 
    return res;    
    }
};