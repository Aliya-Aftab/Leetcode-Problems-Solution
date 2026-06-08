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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }

        queue<pair<TreeNode*, pair<int, int>>> q;
        // ({root, {col/dist, row/level}})
        q.push({root, {0, 0}});
        map<int, vector<vector<int>>> mp;
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int dist = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            
            mp[dist].push_back({level, node->val});
            
            if(node->left){
                q.push({node->left, {dist - 1, level + 1}});
            }
            if(node->right){
                q.push({node->right, {dist + 1, level + 1}});
            }
        }
        
        for(auto &it : mp){
            vector<vector<int>> v = it.second;
            sort(v.begin(), v.end());
            
            vector<int> temp;
            for(auto &node : v){
                temp.push_back(node[1]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};