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
    ListNode* swapNodes(ListNode* head, int k) {
    ListNode* slow=head;
    ListNode* fast=head;
   
    int steps=k-1;
    while(steps--){
    fast=fast->next;
    } 
    ListNode* first=fast;
    while(fast->next!=NULL){
    slow=slow->next;
    fast=fast->next;
    }
    // slow will be at kth node from the end
    int temp=first->val;
    first->val=slow->val;
    slow->val=temp;
    return head;  
    }
};