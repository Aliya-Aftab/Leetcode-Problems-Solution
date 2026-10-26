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
    TreeNode* constructTree(vector<int>& preorder, int &index, int upperBound){
        if(index == preorder.size()){
            return NULL;
        }
        if(preorder[index] > upperBound){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = constructTree(preorder, index, root->val);
        root->right = constructTree(preorder, index, upperBound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return constructTree(preorder, index, INT_MAX);
    }
};