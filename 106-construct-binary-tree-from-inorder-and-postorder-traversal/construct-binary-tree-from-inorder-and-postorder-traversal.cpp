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
     unordered_map<int, int>mp;
public:
    TreeNode* createTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int index){
        if(inStart > inEnd){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[index]);
        int pos=mp[postorder[index]];
        root->right=createTree(inorder, postorder, pos+1, inEnd, index-1);
        root->left=createTree(inorder, postorder, inStart, pos-1, index-(inEnd-pos)-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        for(int i=0; i<n; i++){
            mp[inorder[i]]=i;
        }
        return createTree(inorder, postorder, 0, n-1, n-1 );

    }
};