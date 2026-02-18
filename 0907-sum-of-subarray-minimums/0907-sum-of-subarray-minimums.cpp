class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
    int n=arr.size();
    int MOD=1e9+7;
    long long sum=0;
    vector<int>psi(n,-1);
    vector<int>nsi(n,n);
    stack<int>st;;
    stack<int>rt;
    for(int i=0;i<n;i++){
    while(!st.empty() && arr[st.top()]>arr[i]){
    st.pop();
    }
    if(!st.empty()){
    psi[i]=st.top();
    }
    st.push(i);
    }
    for(int i=n-1;i>=0;i--){
    while(!rt.empty() && arr[rt.top()]>=arr[i]){
    rt.pop();
    }
    if(!rt.empty()){
    nsi[i]=rt.top();
    }
    rt.push(i);
    }
    for(int i=0;i<n;i++){
   long long leftLen = i - psi[i];
long long rightLen = nsi[i] - i;
long long contri = (leftLen * rightLen % MOD) * arr[i] % MOD; 
sum = (sum + contri) % MOD;
    }
    return sum%MOD;
    }
};