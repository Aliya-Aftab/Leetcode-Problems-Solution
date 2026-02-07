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
    void reorderList(ListNode* head) {
    ListNode* slow=head;
    ListNode*fast=head;
    while(fast->next && fast->next->next){
    slow=slow->next;
    fast=fast->next->next;
    }
    // list separated in 2 parts
    ListNode* h1=head;
    ListNode* h2=slow->next;
    slow->next=NULL;
    ListNode* curr=h2;
    ListNode* prev=NULL;
    ListNode* fut=NULL;
    // reversal of second list
    while(curr){
    fut=curr->next;
    curr->next=prev;
    prev=curr;
    curr=fut;
    }
    h2=prev;
    // 1   2        4        3
    // h1   temp1   h2   temp2
    // 1-4   4 2   2 3 
    //
    //
    ListNode* temp1=NULL, *temp2=NULL;
    while(h2){
    temp1=h1->next;
    temp2=h2->next;
    h1->next=h2;
    h2->next=temp1;
    h1=temp1;
    h2=temp2;
    }
    }
};