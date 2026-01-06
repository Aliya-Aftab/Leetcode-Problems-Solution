class Solution {
public: 
    void generate(int n, string &temp, vector<string>&ans, char last ){
    if(temp.size()==n){
    ans.push_back(temp);
    return;
    }
    if(last!='0'){
    temp.push_back('0');
    last='0';
    generate(n,temp,ans,last);
    temp.pop_back();
    }
    temp.push_back('1');
    last='1';
    generate(n, temp,ans, last);
    temp.pop_back();
    }
    vector<string> validStrings(int n) {
    string temp="";
    vector<string>ans;  
    generate(n,temp,ans,' ');
    return ans; 
    }
};