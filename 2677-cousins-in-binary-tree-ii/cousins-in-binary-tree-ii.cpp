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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int>levelSum;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sum=0;
            int n=q.size();
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            levelSum.push_back(sum);
        }

        root->val=0;
        q.push(root);
        int curr=0;

        while(!q.empty()){
            int n=q.size();
            int cousinSum=0;

            if(curr+1 >= levelSum.size()){
                break;
            }

            while(n--){
            int siblingSum=0;
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left){
                siblingSum+=temp->left->val;
            }
            if(temp->right){
                siblingSum+=temp->right->val;
            }

            cousinSum=levelSum[curr+1]-siblingSum;

            if(temp->left){
                temp->left->val=cousinSum;
                q.push(temp->left);
            }
            if(temp->right){
                temp->right->val=cousinSum;
                q.push(temp->right);
            }
            }
              curr++;
        }
        return root;
    }

};
/*
5
13
18
*/