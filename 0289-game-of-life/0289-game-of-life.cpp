class Solution {
public:
    int m, n;
    
    bool isValid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    
    int row[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
    int col[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                int cntOne = 0;
                
                for (int k = 0; k < 8; k++) {
                    int new_i = i + row[k];
                    int new_j = j + col[k];
                    
                    if (isValid(new_i, new_j)) {
                        // CRITICAL CHANGE 1: Check absolute value to see PAST state
                        // -1 means it WAS 1. 
                        // 1 means it IS 1.
                        // Both count as "Live Neighbors".
                        if (abs(board[new_i][new_j]) == 1) {
                            cntOne++;
                        }
                    }
                }

                // Apply Rules
                // Use board[][] directly, but check abs() to know original state
                
                // Rule: If Alive (1) -> Dies (-1)
                if (abs(board[i][j]) == 1) {
                    if (cntOne < 2 || cntOne > 3) {
                        board[i][j] = -1; // Mark as "Was Alive, Now Dead"
                    }
                }
                // Rule: If Dead (0) -> Lives (2)
                else {
                    if (cntOne == 3) {
                        board[i][j] = 2; // Mark as "Was Dead, Now Alive"
                    }
                }
            }
        }

        // Final Pass
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -1) board[i][j] = 0;
                else if (board[i][j] == 2) board[i][j] = 1;
            }
        }
    }
};