class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int cnt=0;
        
        for(int i = 0; i<n; i++){
            vector<int>v(26,0);
            for(int j=i; j<n; j++){
                v[s[j]-'a']++;
                int maxF=INT_MIN;
                int minF=INT_MAX;
                for(int k=0; k<26; k++){
                    if(v[k]==0){
                        continue;
                    }
                    if(v[k] > 0){
                    maxF=max(maxF, v[k]);
                   minF = min(minF, v[k]);
                    }
                   
                }
                cnt+=maxF-minF;
        }
        }
        return cnt;
    }
};