#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
    struct SegmentTree {
        int n;
        vector<int> count;
        vector<double> length;
        vector<int> X;

        SegmentTree(vector<int>& coords) {
            X = coords;
            n = X.size();
            count.resize(4 * n, 0);
            length.resize(4 * n, 0.0);
        }

        void update(int node, int start, int end, int l, int r, int val) {
            if (l >= r) return;
            
            if (l == start && r == end) {
                count[node] += val;
            } else {
                int mid = start + (end - start) / 2;
                update(2 * node, start, mid, l, min(r, mid), val);
                update(2 * node + 1, mid, end, max(l, mid), r, val);
            }

            if (count[node] > 0) {
                length[node] = (double)X[end] - X[start];
            } else {
                if (end - start == 1) {
                    length[node] = 0.0;
                } else {
                    length[node] = length[2 * node] + length[2 * node + 1];
                }
            }
        }

        double getCoveredLength() {
            return length[1]; 
        }
    };

    struct Event {
        int y;
        int type; 
        int x1, x2;

        bool operator<(const Event& other) const {
            if (y != other.y) return y < other.y;
            return type < other.type; 
        }
    };

public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<int> x_coords;
        vector<Event> events;

        for (const auto& sq : squares) {
            int x = sq[0];
            int y = sq[1];
            int l = sq[2];
            x_coords.push_back(x);
            x_coords.push_back(x + l);
            events.push_back({y, 1, x, x + l});
            events.push_back({y + l, -1, x, x + l});
        }

        sort(x_coords.begin(), x_coords.end());
        x_coords.erase(unique(x_coords.begin(), x_coords.end()), x_coords.end());

        auto getXIndex = [&](int val) {
            return lower_bound(x_coords.begin(), x_coords.end(), val) - x_coords.begin();
        };

        sort(events.begin(), events.end());

        SegmentTree st(x_coords);
        double totalArea = 0;
        vector<pair<double, double>> history; 
        
        int prev_y = events[0].y;

        for (const auto& ev : events) {
            int curr_y = ev.y;
            
            if (curr_y > prev_y) {
                double coveredLen = st.getCoveredLength();
                double h = (double)(curr_y - prev_y);
                double stripArea = h * coveredLen;
                
                totalArea += stripArea;
                history.push_back({h, coveredLen});
            }

            int idx1 = getXIndex(ev.x1);
            int idx2 = getXIndex(ev.x2);
            st.update(1, 0, x_coords.size() - 1, idx1, idx2, ev.type);
            
            prev_y = curr_y;
        }

        double target = totalArea / 2.0;
        double currentArea = 0;
        double sweepY = events[0].y; 

        for (auto& p : history) {
            double h = p.first;
            double len = p.second;
            
            if (len == 0) {
                sweepY += h;
                continue;
            }

            double stripArea = h * len;
            
            if (currentArea + stripArea >= target) {
                double needed = target - currentArea;
                return sweepY + (needed / len);
            }
            
            currentArea += stripArea;
            sweepY += h;
        }

        return sweepY;
    }
};