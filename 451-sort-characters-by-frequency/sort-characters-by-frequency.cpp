class Solution {
public:
    static bool compare(const pair<char, int>&a, const pair<char, int>&b){
    return a.second > b.second;
   }
    string frequencySort(string s) {
        int n=s.length();
        vector<pair<char, int>>v(256);
        for(int i=0; i<256; i++){
            v[i].first=char(i);
        }
        for(int i=0; i<n; i++){
            v[s[i]].second++;
        }
        sort(v.begin(), v.end(), compare);
        string ans="";
        for(int i=0; i<256; i++){
            ans+=string(v[i].second, v[i].first);
        }
        return ans;
    }
};