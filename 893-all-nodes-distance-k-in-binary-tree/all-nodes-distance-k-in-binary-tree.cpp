/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&mp){
        if(!root){
            return;
        }
        if(root->left){
            mp[root->left] = root;
        }
        markParent(root->left, mp);
        if(root->right){
            mp[root->right] = root;
        }
        markParent(root->right, mp);
    }

    void collectNodes(TreeNode* target, int k, vector<int>&ans, unordered_map<TreeNode*, TreeNode*>&mp){
        queue<TreeNode*>q;
        unordered_set<TreeNode*>visited;
        q.push(target);
        visited.insert(target);
        while(!q.empty()){
            int size = q.size();
            if(k == 0){
                break;
            }
            while(size--){
                TreeNode* curr = q.front();
                q.pop();
                // left
                if(curr->left && !visited.count(curr->left)){
                    q.push(curr->left);
                    visited.insert(curr->left);
                }
                // right
                if(curr->right && !visited.count(curr->right)){
                    q.push(curr->right);
                    visited.insert(curr->right);
                }
                // parent
                if(mp.count(curr) && !visited.count(mp[curr])){
                    q.push(mp[curr]);
                    visited.insert(mp[curr]);
                }
            }
            k--;
        }
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(!root || !target){
            return ans;
        }
       unordered_map<TreeNode*, TreeNode*>mp;
       markParent(root, mp);
       collectNodes(target, k, ans, mp);
       return ans;

    }
};
// mark parent
// bfs traversal
// empty the queue