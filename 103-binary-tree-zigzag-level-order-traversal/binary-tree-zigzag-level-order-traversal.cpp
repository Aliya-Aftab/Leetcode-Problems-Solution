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
        // base case
        if(!root){
            return ans;
        }

        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        s1.push(root);

        while(!s1.empty() || !s2.empty()){
            vector<int>temp;
            if(!s1.empty()){
                while(!s1.empty()){
                    TreeNode* node = s1.top();
                    s1.pop();
                    temp.push_back(node->val);
                    if(node->left){
                        s2.push(node->left);
                    }
                    if(node->right){
                        s2.push(node->right);
                    }
                }
                ans.push_back(temp);
            }
            else{
                while(!s2.empty()){
                    TreeNode* node = s2.top();
                    s2.pop();
                    temp.push_back(node->val);
                    if(node->right){
                        s1.push(node->right);
                    }
                    if(node->left){
                        s1.push(node->left);
                    }
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};