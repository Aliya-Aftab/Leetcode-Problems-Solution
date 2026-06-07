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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*>mp;
        unordered_set<int>childSet;

        for(int i=0; i<descriptions.size(); i++){
            int parent=descriptions[i][0];
            int child=descriptions[i][1];
            int isLeft=descriptions[i][2];

            if(mp.find(parent)==mp.end()){
                mp[parent]=new TreeNode(parent);
            }
            if(mp.find(child)==mp.end()){
                mp[child]=new TreeNode(child);
            }

            if(isLeft==1){
                mp[parent]->left=mp[child];
            }
            else{
                mp[parent]->right=mp[child];
            }
            childSet.insert(child);
        }

        for(int i=0; i<descriptions.size(); i++){
            int parent=descriptions[i][0];
            if(!childSet.count(parent)){
                return mp[parent];
            }
        }
        return NULL;
    }
};

/*
20 -> 15, 17
50 -> 20, 80
80 -> 19, Null

        50
   20       80
 15   17  19

*/