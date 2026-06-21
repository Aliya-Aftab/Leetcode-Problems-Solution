class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        int maxEl=costs[0];
        for(int i=1; i<n; i++){
            maxEl=max(maxEl, costs[i]);
        }
        vector<int>count(maxEl+1, 0);
        for(int i=0; i<n; i++){
            count[costs[i]]++;
        }
        int iceCreamCnt=0;
        for(int price=1; price<=maxEl; price++){
            if(count[price] == 0){
                continue;
            }
            if(coins < price){
                break;
            }
            int quantity=min(count[price], coins/price);
            iceCreamCnt += quantity;
            coins-=quantity*price;
        }
        return iceCreamCnt;
    }
};