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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            bool foundX = false;
            bool foundY = false;

            while(n--) {
                TreeNode* temp = q.front();
                q.pop();

                if (temp->val == x) foundX = true;
                if (temp->val == y) foundY = true;

                if (temp->left && temp->right) {
                    if ((temp->left->val == x && temp->right->val == y) ||
                        (temp->left->val == y && temp->right->val == x)) {
                        return false;
                    }
                }

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            if (foundX && foundY) return true;
            if (foundX || foundY) return false;
        }
        return false;
    }
};

/*
single traversal code -> 
*/