class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());

        // Pair each value in nums2 with its original index
        // Priority queue acts as a max-heap to give the largest opponent values first
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums2[i], i});
        }

        vector<int> ans(n);
        int low = 0;
        int high = n - 1;

        while (!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();

            // If our best card can beat this opponent card, use it
            if (nums1[high] > val) {
                ans[idx] = nums1[high];
                high--;
            } 
            // Otherwise, sacrifice our weakest card
            else {
                ans[idx] = nums1[low];
                low++;
            }
        }

        return ans;
    }
};

/*
nums1[i] > nums2[i] => r
i need to maximise the advantage of nums1 wrt nums2
so if i have any number in my nums 2, I need to have a number which is just greater than nums 2's number.
I can store the elements of nums1 into a min heap, so when I have the 
to take element I will first try to satisfy the condition with the min element from nums 1.
nums1 = [2,7,11,15], nums2 = [1,10,4,11]
min heap={2, 7, 11, 15}
i = 0, ans = 2, pq = {7, 11, 15}
i = 1, ans = 2, 11  pq = {7, 15}
i = 2, ans = 2, 11, 7  pq={15}
i = 3, ans = 2, 11, 7, 15

nums1 = [12,24,8,32], nums2 = [13,25,32,11]
pq = [12,24,8,32]
i = 0, nums1= 24, pq = [8, 12, 32]
i = 1, nums1 = 24, 32 pq = [8, 12]
i = 2, nums1 = 24, 32, 12, 8

*/