class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    string ans="";
    sort(strs.begin(),strs.end());
    string first=strs[0];
    string last=strs[strs.size()-1];
    int i=0, j=0;
    while(i<first.length() && j<last.length()){
    if(first[i]==last[j]){
    ans+=first[i];
    i++;
    j++;
    }
    else {
        break;
    }

    }
    return ans;    
    }
};