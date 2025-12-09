class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    int n1=nums1.size();
    int n2=nums2.size();
    if (n1>n2){
    return intersection(nums2, nums1);
    }
    unordered_set<int>s(nums1.begin(), nums1.end());
    vector<int>ans;
    for(int i=0;i<n2;i++){
    if(s.count(nums2[i])){
    ans.push_back(nums2[i]);
    s.erase(nums2[i]);
    }
    } 
    return ans;   
    }
};