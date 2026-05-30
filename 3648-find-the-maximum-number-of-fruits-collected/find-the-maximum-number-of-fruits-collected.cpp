class Solution {
public:
    int n;
    int child2(int i, int j, vector<vector<int>>& fruits, vector<vector<int>>&t2){
        if(i == n-1 && j == n-1){
            return 0;
        }
        // handling boundary
        if(i>=n || j<0 || j>=n || j<=i){
            return -1e9;
        }
        if(t2[i][j]!=-1){
            return t2[i][j];
        }
        int left=child2(i+1, j-1, fruits, t2);
        int down=child2(i+1, j, fruits, t2);
        int right=child2(i+1, j+1, fruits, t2);
        return t2[i][j]=fruits[i][j] + max({left, down, right});
    }
    
    int child3(int i, int j, vector<vector<int>>& fruits, vector<vector<int>>&t3){
         if(i == n-1 && j == n-1){
            return 0;
        }
        // handling boundary
        if(i>=n || i<0|| j<0 || j>=n || i<=j){
            return -1e9;
        }
        if(t3[i][j]!=-1){
            return t3[i][j];
        }
        int topRight=child3(i-1, j+1, fruits,t3);
        int right=child3(i, j+1, fruits,t3);
        int bottomRight=child3(i+1, j+1, fruits,t3);
        return t3[i][j]= fruits[i][j] + max({topRight, right, bottomRight});
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n=fruits.size();
        vector<vector<int>>t2(n, vector<int>(n, -1));
        vector<vector<int>>t3(n, vector<int>(n, -1));
        int c1=0;
        for(int i=0; i<n; i++){
            c1+=fruits[i][i];
        }
        int c2=child2(0, n-1, fruits, t2);
        int c3=child3(n-1, 0, fruits, t3);
        return c1+c2+c3;
    }
};

/*
each child has to make exactly n-1 moves.
child 1: if has to reach n-1, n-1 => only possible move is moving diagonally, otherwise it wouldn't be able to reach in n-1 steps.
child 2: since, child 1 has picked up diagonal elements => 
child 2 can't move in diagonals(i==j). Note, for reaching at
n-1, n-1 cell,  child 2 has to take steps only in the one triangular phase. It cannot move where i>j.
child 3: similar case as of child 2 => will not move to (i==j && j>i). 

IMP : 2 ways to handle diagonals
1. move dest check above, then include for invalid check using equality.
2. keeping no equality signs for upper/ lower invaid triangles. Instead setting the diagonals cell = 0 after picking elements.
*/