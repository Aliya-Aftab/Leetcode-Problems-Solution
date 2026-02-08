class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    int n=heights.size();
    stack<int>st;
    int maxArea=0;
    for(int i=0;i<n;i++){
    while(!st.empty() && heights[i]<heights[st.top()]){
    int index=st.top();
    st.pop();
    if(!st.empty()){
    maxArea=max(maxArea, heights[index]*(i-st.top()-1));
    }
    else{
    maxArea=max(maxArea, heights[index]*i);
    }
    }
    st.push(i);
    }
    while(!st.empty()){
    int index=st.top();
    st.pop();
    if(!st.empty()){
    maxArea=max(maxArea, heights[index]*(n-st.top()-1));
    }
    else{
    maxArea=max(maxArea, heights[index]*n );
    }
    } 
    return maxArea;   
    }
};