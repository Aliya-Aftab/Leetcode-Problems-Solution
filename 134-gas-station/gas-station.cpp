class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0;
        int totalCost = 0;
        int currGas = 0;
        int start = 0;
        for(int i = 0; i < n; i++){
            totalGas += gas[i];
            totalCost += cost[i];
            currGas += gas[i] - cost[i];
            if(currGas < 0){
                start = i + 1;
                currGas = 0;
            }
        }

       return totalGas < totalCost ? -1 : start ;
    }
};
/*
gas = [1,2,3,4,5], cost = [3,4,5,1,2]
begin with empty tank at one of the station, return starting gas station
if we can travel around the circuit once in the clockwise direction.
There is only one such index only through which the circuit can be completed.

gas = [2,3,4], cost = [3,4,3]
idx=  [0,1,2]

*/