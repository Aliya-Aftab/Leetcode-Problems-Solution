class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        if(n==1){
            return cost[0];
        }
        if(n==2){
            return cost[0] + cost[1];
        }
        sort(cost.rbegin(), cost.rend());
         int minCost=0;
         int cnt=0;
         for(int i=0; i<n; i++){
            cnt++;
            if(cnt%3!=0){
                minCost+=cost[i];
            }
         }
        return minCost;
    }
};
/*
6,5,7,9,2,2   
 sorted in desc order -> 9, 7, 6, 5, 2, 2
 [10,5,9,4,1,9,10,2,10,8]
   
  0   1   2   3  4  5  6  7  8  9
 [10, 10, 10, 9, 9, 8, 5, 4, 2, 1]



*/