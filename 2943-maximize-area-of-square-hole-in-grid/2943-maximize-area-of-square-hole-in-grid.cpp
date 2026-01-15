class Solution {
public:
    int maxConsecutive(vector<int>& bars) {
        sort(bars.begin(), bars.end());
        int maxLen = 1, curr = 1;

        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1) {
                curr++;
                maxLen = max(maxLen, curr);
            } else {
                curr = 1;
            }
        }
        return maxLen + 1;  // +1 for cell gap
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxH = maxConsecutive(hBars);
        int maxV = maxConsecutive(vBars);

        int side = min(maxH, maxV);
        return side * side;
    }
};
