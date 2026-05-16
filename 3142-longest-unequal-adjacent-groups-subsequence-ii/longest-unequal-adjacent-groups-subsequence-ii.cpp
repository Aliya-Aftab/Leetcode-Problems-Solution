class Solution {
public:
    bool hammingDist(string &s1, string &s2){
      int diff=0;
      for(int i=0;i<s1.length();i++){
        if(s1[i]!=s2[i]){
            diff++;
        }
        if(diff > 1){
            return false;
        }
      } 
      return diff==1; 
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<int>dp(n,1);
        vector<int>parent(n, -1);
        int longestSub=1;
        int longestSubIdx=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(groups[i]!=groups[j] && words[i].length()==words[j].length() && hammingDist(words[i], words[j])){
            
            if(dp[j]+1 > dp[i]){
                dp[i]=dp[j] + 1;
                parent[i]=j;
                if(longestSub < dp[i]){
                    longestSub=dp[i];
                    longestSubIdx=i;
                }
            }
                }
            }
        }
        vector<string>ans;
        while(longestSubIdx !=- 1){
            ans.push_back(words[longestSubIdx]);
            longestSubIdx=parent[longestSubIdx];
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};

/*
dp[i] - length of longest subseq ending at idx i, following given 3 conditions:
hamming dist==1
adj indices are unequal in groups
words are of same length
*/