class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double total = 0;
        double low = 1e18, high = 0;

        for (auto &s : squares) {
            total += (double)s[2] * s[2];
            low = min(low, (double)s[1]);
            high = max(high, (double)s[1] + s[2]);
        }

        double half = total / 2.0;

        for (int i = 0; i < 70; i++) {
            double mid = (low + high) / 2.0;
            double area = 0;

            for (auto &s : squares) {
                double y = s[1], l = s[2];
                if (mid > y) {
                    area += l * min(l, mid - y);
                }
            }

            if (area < half) low = mid;
            else high = mid;
        }

        return low;
    }
};
