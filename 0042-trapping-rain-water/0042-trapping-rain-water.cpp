class Solution {
public:
    int trap(vector<int>& height) {
    int n=height.size();
    int leftMax=0;
    int rightMax=0;
    int water=0;
    int maxHeight=height[0];
    int maxIdx=0;
    for(int i=1; i<n ;i++){
    if(height[i]>maxHeight){
    maxHeight=height[i];
    maxIdx=i;
    }
    }
    for(int i=0; i<maxIdx; i++){
    if(leftMax>height[i]){
    water+=leftMax-height[i];
    }
    leftMax=max(leftMax,height[i]);
    } 
    for(int i=n-1;i>maxIdx;i--){
    if(rightMax>height[i]){
    water+=rightMax-height[i];
    }
    rightMax=max(rightMax, height[i]);
    }
    return water; 
    }
};