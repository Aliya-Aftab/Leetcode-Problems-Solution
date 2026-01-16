class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1e9 + 7;

        // Add boundary fences (cannot be removed)
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<long long> hGaps, vGaps;

        // Calculate all possible horizontal gaps
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hGaps.insert(hFences[j] - hFences[i]);
            }
        }

        // Calculate all possible vertical gaps
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                vGaps.insert(vFences[j] - vFences[i]);
            }
        }

        long long maxSide = 0;

        // Find maximum common gap
        for (auto gap : hGaps) {
            if (vGaps.count(gap)) {
                maxSide = max(maxSide, gap);
            }
        }

        if (maxSide == 0) return -1;

        return (maxSide * maxSide) % MOD;
    }
};
