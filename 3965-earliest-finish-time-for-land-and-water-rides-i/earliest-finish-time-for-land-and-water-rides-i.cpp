class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int m = landStartTime.size();
        int n = waterStartTime.size();
        int mini = INT_MAX;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int landFinishTime = landStartTime[i] + landDuration[i];
                int landToWater = max(landFinishTime, waterStartTime[j]) + waterDuration[j];
                mini=min(mini, landToWater);
                
                int waterFinishTime = waterStartTime[j] + waterDuration[j];
                int waterToLand = max(waterFinishTime, landStartTime[i]) + landDuration[i];
                mini = min(mini, waterToLand);
            }
        }
        
        return mini;
    }
};