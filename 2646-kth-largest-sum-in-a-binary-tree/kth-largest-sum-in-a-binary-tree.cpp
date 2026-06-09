/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;

        queue<TreeNode*> q;
        q.push(root);
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        while (!q.empty()) {
            int size = q.size();
            long long level_sum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level_sum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            pq.push(level_sum);
            if (pq.size() > k) {
                pq.pop();
            }
        }

        if (pq.size() < k) return -1;
        return pq.top();
    }
};