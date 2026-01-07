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
    int total=0;
    pair<int, int>solve(TreeNode* root){
    // base case
    if(!root){
    return {0,0};
    }
    pair<int,int>left=solve(root->left);
    pair<int,int>right=solve(root->right);
    int currSum=left.first+ right.first+root->val;
    int currCount=left.second+ right.second + 1;
    if(currSum/ currCount==root->val){
    total++;
    }
    return {currSum, currCount};
    }
    int averageOfSubtree(TreeNode* root) {
    solve(root);
    return total;  
    }
};