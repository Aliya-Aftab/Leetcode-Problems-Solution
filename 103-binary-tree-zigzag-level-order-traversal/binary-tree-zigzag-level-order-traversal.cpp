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
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(!root){
            return ans;
        }
        int cnt=0;
        q.push(root);
        vector<int>temp;
        
        while(!q.empty()){
            int n=q.size();
            temp.clear();
            while(n--){
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }

            if(cnt % 2 == 1){
                reverse(temp.begin(), temp.end());
            }
            ans.push_back(temp);
            cnt++;
        }
        return ans;

    }
};