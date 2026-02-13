class Solution {
public:
    string removeKdigits(string num, int k) {
    int n=num.length();
    string temp="";
    for(int i=0;i<n;i++){
    while(!temp.empty() && temp.back()> num[i] && k>0){
    temp.pop_back();
    k--;
    }
    temp.push_back(num[i]);
    }
    while(!temp.empty() && k>0){
    temp.pop_back();
    k--;
    }
    int j=0 ;
    while(j<temp.size() && temp[j]=='0'){
    j++;
    }
    temp=temp.substr(j);
    if(temp.empty()){
    return "0";
    }
    return  temp;
    }
};