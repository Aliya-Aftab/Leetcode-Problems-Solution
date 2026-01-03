class Solution {
public:
    string getPermutation(int n, int k) {
    vector<char>digits;
    k--;
    for(int i=1;i<=n;i++){
    digits.push_back(i+'0');
    } 
    vector<int>factorials(n);
    factorials[0]=1;
    for(int i=1;i<n;i++){
    factorials[i]=factorials[i-1]*i;
    }
    string answer="";
    for(int i=n;i>=1;i--){
    int block=factorials[i-1];
    int idx=k/block;
    answer+=digits[idx];
    digits.erase(digits.begin()+idx);
    k=k%block;
    }
    return answer;
    }
};