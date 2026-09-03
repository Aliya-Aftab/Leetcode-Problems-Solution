class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n2 = costs.size();
        sort(costs.begin(), costs.end(), [](const vector<int>&a, const vector<int>&b){
             return (a[0] - a[1]) < (b[0] - b[1]);
        });
        int sum = 0;
        int n = n2/2;
        for(int i = 0; i < n2; i++){
            if(i < n){
                sum += costs[i][0];
            }
            else{
                sum += costs[i][1];
            }
        }
        return sum;
    }
};
/*
costs = [[10,20],[30,200],[400,50],[30,20]]
index = [0,         1,       2,       3]



costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
index = [0,         1,       2,        3,        4,        5]
A = 
B = 
*/