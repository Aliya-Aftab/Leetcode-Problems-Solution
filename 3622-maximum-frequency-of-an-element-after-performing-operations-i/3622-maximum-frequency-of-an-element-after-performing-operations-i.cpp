class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
    int n=nums.size();
    int maxEl= *max_element(nums.begin(), nums.end()) +k;   
    vector<int>freq(maxEl+1, 0);
    for(int &num: nums){
    freq[num]++;
    }
    // cummulative sum of freq
    for(int i=1;i<=maxEl;i++){
    freq[i]+=freq[i-1];
    }
    int result=0;
    for(int target=0; target<=maxEl; target++){
    if(freq[target]==0){
    continue;
    }
    int l=max(target-k, 0);
    int r=min(maxEl,target+k);
    int totalCount=freq[r]-(l>0 ? freq[l-1] : 0 );
    int targetCount=freq[target]- (target>0 ? freq[target-1] : 0);
    int needConv=totalCount-targetCount;
    int maxPossibleFreq=targetCount + min(needConv, numOperations);
    result=max(result, maxPossibleFreq);
    }
    return result;
    }
};