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
     unordered_map<int, int>mp;
    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, int index){
        // base case
        if(inStart > inEnd){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[index]);
        int pos=mp[preorder[index]];
        root->left=createTree(preorder, inorder, inStart, pos-1, index+1);
        root->right=createTree(preorder, inorder, pos+1, inEnd, index+(pos-inStart)+1);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0; i<n; i++){
            mp[inorder[i]]=i;
        }
        return createTree(preorder, inorder, 0, n-1, 0);

    }
};