class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m=s.length();
        int n=t.length();
        if(m!=n){
            return false;
        }
        vector<char>v1(256, -1);
        vector<char>v2(256, -1);
        for(int i=0; i<n; i++){
            if(v1[s[i]]!=-1 && v1[s[i]]!=t[i]){
                return false;
            }
            if(v2[t[i]]!=-1 && v2[t[i]]!=s[i]){
                return false;
            }
            v1[s[i]]=t[i];
            v2[t[i]]=s[i];
        }
        return true;
    }
};