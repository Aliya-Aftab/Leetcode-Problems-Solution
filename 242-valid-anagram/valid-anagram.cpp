class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq1(26, 0);
        for(char ch : s){
            freq1[ch-'a']++;
        }
        for(char ch : t){
            freq1[ch-'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(freq1[i] != 0){
                return 0;
            }
        }
        return 1;
    }
};