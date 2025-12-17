class Solution {
public:
    int longestMountain(vector<int>& arr) {
    int n=arr.size();
    if(n<3){
    return 0;
    } 
    int i=0;
     int maxi=0;
    while(i<n-1)
    {
    int upCnt=0;
    int downCnt=0;
    while(i<n-1 && arr[i]<arr[i+1]){
    upCnt++;
    i++;
    }
    while(i<n-1 && arr[i]>arr[i+1]){
    downCnt++;
    i++;
    }
    if(upCnt>0 && downCnt>0){
    maxi=max(maxi, upCnt+downCnt+1);
    }
    if(i < n - 1 && arr[i] == arr[i+1]){
    i++;
    }
    }
    return maxi;
    }
};