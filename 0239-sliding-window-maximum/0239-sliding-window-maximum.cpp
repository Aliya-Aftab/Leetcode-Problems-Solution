class Solution {
public:
    /*
    1.when new element nums[i] comes,make space for it(window size can't be greater than k).
    2.now,when nums[i] comes , there is no need to keep small elements in that window,pop them.
    3.push i in deque for nums[i].
    4.if i>=k-1,then dq.front() is our answer for that window.
    */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n=nums.size();
    deque<int>dq;
    vector<int>res;
    for(int i=0;i<n;i++){
    // 1. make space 
    while(!dq.empty() && dq.front()<=i-k){
    dq.pop_front();
    }
    // 2. pop all smaller elements
    while(!dq.empty() && nums[i]>=nums[dq.back()]){
    dq.pop_back();
    }
    // 3.push idx in deque
    dq.push_back(i);
    // 4.push req ans.
    if(i>=k-1){
    res.push_back(nums[dq.front()]);
    }
    } 
    return res;
    }
};