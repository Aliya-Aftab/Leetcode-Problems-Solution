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
    ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next){
    return head;
    }
    ListNode* oddEl=head;
    ListNode* evenEl=head->next;
    ListNode* evenHead=head->next;
    while(evenEl && evenEl->next){
    oddEl->next=evenEl->next;
    oddEl=oddEl->next;

    evenEl->next=oddEl->next;
    evenEl=evenEl->next;
    }
    oddEl->next=evenHead;
    return head;
    }
};