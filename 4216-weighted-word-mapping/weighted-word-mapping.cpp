class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string ans="";
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=0; j<words[i].size(); j++){
                sum+=weights[words[i][j]-'a'];
            }
            sum%=26;
            int revIdx=25-sum;
            ans+=revIdx+'a';
        }
        return ans;
    }
};