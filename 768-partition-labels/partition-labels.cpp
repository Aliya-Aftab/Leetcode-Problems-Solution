class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int>lastIdx(26, 0);

        for(int i = 0; i < n; i++){
            lastIdx[s[i]-'a'] = i;
        }
        vector<int>ans;
        int i = 0;
        int start = 0;
        int end = 0;
        while(i < n){
            end = max(end, lastIdx[s[i]-'a']);
            if(i == end){
                ans.push_back(end-start+1);
                start = end+1;
            }
            i++;
        }
        return ans;
    }
};
/*

*/