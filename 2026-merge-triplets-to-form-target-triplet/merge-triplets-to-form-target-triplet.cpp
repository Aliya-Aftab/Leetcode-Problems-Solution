class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        bool has0 = false;
        bool has1 = false;
        bool has2 = false;
        for(int i = 0; i < n; i++){
           if(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]){
                continue;
           }
           
           if(triplets[i][0] == target[0])
           has0 = true;
           if(triplets[i][1] == target[1])
           has1 = true;
           if(triplets[i][2] == target[2])
           has2 = true;
           if(has0 && has1 && has2){
            return true;
           }
        }
        return has0 && has1 && has2;
    }
};

/*
triplet is an array of 3 integers.
triplets = [[2,5,3],[1,8,4],[1,7,5]], target = [2,7,5]
*/