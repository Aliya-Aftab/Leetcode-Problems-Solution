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
    int findDiameter(TreeNode* root, int &maxD){
    if(!root){
    return 0;
    }
    int l=findDiameter(root->left, maxD);
    int r=findDiameter(root->right, maxD);
    maxD=max(maxD, l+r);
    return max(l, r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
    int maxD=INT_MIN;
    findDiameter(root, maxD);
    return maxD;   
    }
};