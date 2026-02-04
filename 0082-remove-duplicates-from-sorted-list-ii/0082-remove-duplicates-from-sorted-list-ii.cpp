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
    if(!head || !head->next){
    return head;
    }
    ListNode* prev=head;
    ListNode* curr=head->next;
    ListNode* dummy=new ListNode(101);
    dummy->next=head;
    ListNode* prev2=dummy;
    while(curr){
    if(prev->val==curr->val){
    while(curr && curr->val==prev->val){
    curr=curr->next;
    }
    prev2->next=curr;
    prev=prev2->next;
    if(prev){
    curr=prev->next;
    }
    }
    else{
    prev2=prev;
    prev=curr;
    curr=curr->next;
    } 
    }
    return dummy->next;  
    }
};