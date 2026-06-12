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
    void solve(TreeNode* node, int step, int &maxPath , bool goLeft){
        if(!node){
            return ;
        }
        maxPath=max(maxPath, step);
        if(goLeft){
           solve(node->left, step+1, maxPath, false); 
           solve(node->right, 1, maxPath, true);
        }
        else{
            solve(node->right, step+1,maxPath, true);
            solve(node->left, 1,maxPath,  false);
        }
    }
    int longestZigZag(TreeNode* root) {
        if(!root){
            return 0;
        }
        int maxPath=0;
        solve(root, 0, maxPath, true);
        solve(root, 0, maxPath, false);
        return maxPath;
    }
};