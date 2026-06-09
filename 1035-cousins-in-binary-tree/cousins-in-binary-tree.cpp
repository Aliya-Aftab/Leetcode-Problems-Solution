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
    bool isParent(TreeNode* root, int x, int y){
        if(!root){
            return false;
        }
        if(root->left && root->right){
            if(root->left->val==x && root->right->val==y){
                return true;
            }
            if(root->left->val==y && root->right->val==x){
                return true;
            }
        }
        return isParent(root->left, x, y) || isParent(root->right, x, y);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        int l1=-1, l2=-1;

        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->val==x){
                    l1=level;
                }
                if(temp->val==y){
                    l2=level;
                }
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            // x and y are on different levels
            if(l1!=l2){
                return false;
            }
            // x and y are found on same level, stopping bfs
            if(l1!=-1 ){
                break;
            }
            level++;
        }
        return !isParent(root, x, y);
    }
};