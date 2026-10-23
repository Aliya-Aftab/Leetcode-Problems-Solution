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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        int count = 0;
        while(!q.empty()){
           int size = q.size();
           int total = size; 
           vector<int>temp(size);
           int i = 0;
           while(size--){
            TreeNode* node = q.front();
            q.pop();
            
            if(count % 2 == 0){
                temp[i] = node->val;
            }
            else{
                temp[total - 1 - i] = node->val;
            }
            i++;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
           }
           ans.push_back(temp);
           count++;
        }
        return ans;
    }
};