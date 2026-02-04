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
    ListNode* deleteDuplicates(ListNode* head) {
    if(!head){
    return NULL;
    }
    vector<int>ans;
    ans.push_back(head->val);
    ListNode* temp=head->next;
    while(temp){
    if(ans.back()!=temp->val){
    ans.push_back(temp->val);
    }
    temp=temp->next;
    }
    temp=head;
    int idx=0;
    while(idx<ans.size()){
    temp->val=ans[idx];
    idx++;
    temp=temp->next;
    }
    temp=head;
    idx=ans.size()-1;
    while(idx--){
    temp=temp->next;
    }
    temp->next=NULL;
    return head;
    }
};