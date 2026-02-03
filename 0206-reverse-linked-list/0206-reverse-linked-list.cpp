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
    ListNode* reverseList(ListNode* head) {
    if(!head){
    return NULL;
    }
    vector<int>v;
    ListNode* temp=head;
    while(temp){
    v.push_back(temp->val);
    temp=temp->next;
    }
    reverse(v.begin(), v.end());
    ListNode* newHead;
    newHead=new ListNode (v[0]);
    temp=newHead;
    for(int i=1;i<v.size();i++){
    temp->next=new ListNode(v[i]);
    temp=temp->next;
    }
    return newHead;
    }
};