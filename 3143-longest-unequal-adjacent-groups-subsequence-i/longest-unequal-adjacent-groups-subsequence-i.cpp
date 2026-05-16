class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
       int n=words.size();
       vector<string>ans;
       ans.push_back(words[0]);
        if(n==1){
        return ans;
       }

       int prev=0;
       for(int i=1;i<n;i++){
         if(groups[prev]!=groups[i]){
            ans.push_back(words[i]);
            prev=i;
         }
       }
       return ans;
    }
};