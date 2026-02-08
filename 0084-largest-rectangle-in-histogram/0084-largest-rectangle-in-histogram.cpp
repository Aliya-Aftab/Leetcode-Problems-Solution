class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    int n=heights.size();
    vector<int>nse(n,0);
    vector<int>pse(n,0);
    stack<int>st;
    // next smaller element
    for(int i=0;i<n;i++){
    while(!st.empty() && heights[i]<heights[st.top()]){
    nse[st.top()]=i;
    st.pop();
    }
    st.push(i);
    }
    while(!st.empty()){
    nse[st.top()]=n;
    st.pop();
    }
    // prev smaller element
    for(int i=n-1;i>=0;i--){
    while(!st.empty() && heights[i]<heights[st.top()]){
    pse[st.top()]=i;
    st.pop();
    }
    st.push(i);
    }
    while(!st.empty()){
    pse[st.top()]=-1;
    st.pop();
    }
    int maxArea=0;
    for(int i=0;i<n;i++){
    int width=nse[i]-pse[i]-1;
    int area=heights[i]* width;
    maxArea=max(maxArea,area );
    } 
    return maxArea;  
    }
};