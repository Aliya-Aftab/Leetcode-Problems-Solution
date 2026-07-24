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
ListNode* middle(ListNode* head){
    if(!head){
        return NULL;
    }
    ListNode* slow=head;
    ListNode* fast=head->next;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy =new ListNode(0);
        ListNode *tail=dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next=l1;
                l1=l1->next;
            }
            else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        tail->next = l1 ? l1 : l2;
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* mid=middle(head);
        ListNode* rightMid=mid->next;
        mid->next=NULL;
        ListNode* left=sortList(head);
        ListNode* right=sortList(rightMid);
        return merge(left, right);
    }
    
};