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
    ListNode* rev(ListNode* head){
        if(!head){
            return NULL;
        }
        ListNode* prev = NULL;
        while(head){
            ListNode* fut = head->next;
            head->next = prev;
            prev = head; 
            head = fut;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* revHead = rev(head);
        ListNode* curr = revHead;
        ListNode* tail = NULL;
        int mul=1;
        int carry=0;
        while(curr){
            mul = curr->val*2 + carry;
            curr->val = mul%10;
            carry = mul/10;
            tail= curr;
            curr = curr->next;
        }
        if(carry){
          tail->next = new ListNode(carry%10);
            tail = tail->next;
        }
        revHead= rev(revHead);
        return revHead;
    }
};