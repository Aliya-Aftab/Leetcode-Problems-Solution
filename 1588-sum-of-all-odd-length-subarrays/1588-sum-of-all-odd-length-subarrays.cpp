class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
    int n=arr.size();
    int totalSum=0;
    for(int i=0;i<n;i++){
    int sum=0;
    for(int j=i;j<n;j++){
    sum+=arr[j];
    int len=j-i+1;
    if(len%2==1){
    totalSum+=sum;
    }
    }
    }
    return totalSum;    
    }
};