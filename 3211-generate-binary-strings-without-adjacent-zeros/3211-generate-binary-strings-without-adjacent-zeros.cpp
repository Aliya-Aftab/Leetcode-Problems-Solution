class Solution {
public: 
    void generate(int n, string &temp, vector<string>&ans, char last ){
    if(temp.size()==n){
    ans.push_back(temp);
    return;
    }
    if(last!='0'){
    temp.push_back('0');
    generate(n,temp,ans,'0');
    temp.pop_back();
    }
    temp.push_back('1');
    generate(n, temp,ans, '1');
    temp.pop_back();
    }
    vector<string> validStrings(int n) {
    string temp="";
    vector<string>ans;  
    generate(n,temp,ans,' ');
    return ans; 
    }
};