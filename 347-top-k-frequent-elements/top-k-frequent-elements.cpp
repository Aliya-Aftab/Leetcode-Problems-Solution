class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        // ele => freq
        unordered_map<int, int>mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        // index = freq, value = elements, bucket[i] = elements having i frequency
        vector<vector<int>>bucket(n+1);
        for(auto &it: mp){
            int ele = it.first;
            int freq = it.second;
            bucket[freq].push_back(ele);
        }

        // iterating from backward to get the highest freq element
        vector<int>res;
        for(int i = n; i >= 0; i--){
            if(bucket[i].size() == 0){
                continue;
            }
            while(bucket[i].size() > 0 && k > 0){
                res.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return res;
    }
};