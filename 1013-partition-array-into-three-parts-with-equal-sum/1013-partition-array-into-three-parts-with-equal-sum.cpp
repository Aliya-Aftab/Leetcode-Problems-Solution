class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
    int n=arr.size();
    long long sum=0;
    for(int num: arr){
    sum+=num;
    }
    if(sum%3!=0){
    return false;
    }
    int count=0;
    int currSum=0;
    for(int i=0;i<n;i++){
    currSum+=arr[i];
    if(currSum==sum/3){
    count++;
    currSum=0;
    }
    }
    if(count>=3){
    return true;
    }
    return false;   
    }
};