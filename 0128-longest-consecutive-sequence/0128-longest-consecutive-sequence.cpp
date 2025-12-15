class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    int n=nums.size();
    if(n==0){
    return 0;
    } 
    set<int>st;
    int cnt=0;
    int longest=0;
    int x;
    for(int num: nums){
    st.insert(num);
    } 
    for(auto it: st){
    if(st.find(it-1)==st.end()){
    cnt=1;
    x=it;
    while(st.find(x+1)!=st.end()){
    cnt++;
    x=x+1;
    }
    longest=max(longest,cnt);
    }
    } 
    return longest; 
    }
};