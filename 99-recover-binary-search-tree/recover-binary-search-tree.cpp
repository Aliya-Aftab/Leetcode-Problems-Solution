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
    TreeNode* prev = NULL, *first = NULL, *last = NULL;
    void inorder(TreeNode* root){
        if(!root){
            return ;
        }
        inorder(root->left);
        if(prev!=NULL && root->val < prev->val){
            if(first == NULL){
                first = prev;
            }
            last = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(!root){
            return;
        }
        inorder(root);
        int temp;
        temp = first->val;
        first->val = last->val;
        last->val = temp; 
    }
};