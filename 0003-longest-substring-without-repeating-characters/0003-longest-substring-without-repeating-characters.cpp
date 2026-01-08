class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int n=s.length();
    int i=0,j=0;
    vector<int>freq(256,0);
    int longest=0;
    while(j<n){
    while(freq[s[j]]){
    freq[s[i]]--;
    i++;
    }
    longest=max(longest, j-i+1);
    freq[s[j]]++;
    j++;
    }  
    return longest;
    }
};