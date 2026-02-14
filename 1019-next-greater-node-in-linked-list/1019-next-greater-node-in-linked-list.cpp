/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
    vector<int>v;
    ListNode* temp=head;
    while(temp){
    v.push_back(temp->val);
    temp=temp->next;
    }
    int n=v.size();
    stack<int>st;
    vector<int>ans(n,0); 
   for(int i=0;i<v.size();i++){
   while(!st.empty() && v[i]>v[st.top()]){
   ans[st.top()]=v[i];
   st.pop();
   }
   st.push(i);
   }
   return ans;
    }
};