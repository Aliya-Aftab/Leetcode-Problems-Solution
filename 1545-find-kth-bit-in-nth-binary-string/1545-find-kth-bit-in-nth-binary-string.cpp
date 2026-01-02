class Solution {
public:
    
    char findKthBit(int n, int k) {
    // base case
    if(n==1 && k==1){
    return '0';
    }
    int len=pow(2,n) - 1;
    int mid=len/2;
    if(k<=mid){
    return findKthBit(n-1,k);
    }
    else if(k==mid+1){
    return '1';
    }
    else{
    char ans= findKthBit(n-1, len-k+1);
    if(ans=='0'){
    return '1';
    }
    else{
    return '0';
    }
    } 
    return '0';
    }
};