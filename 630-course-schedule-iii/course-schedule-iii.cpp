class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
       sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int>pq;
        int currTime = 0;
        for(int i = 0; i < n; i++){
            int d = courses[i][0];
            int l = courses[i][1];
            if(currTime + d <= l){
                currTime += d;
                pq.push(d);
            }
            else{
                if(!pq.empty() && pq.top()>d){
                    currTime-=pq.top();
                    pq.pop();
                    currTime+=d;
                    pq.push(d);
                }
            }
        }
        return pq.size();
    }
};