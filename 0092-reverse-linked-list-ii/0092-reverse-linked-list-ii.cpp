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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode* dummy=new ListNode(0);
    dummy->next=head;
    ListNode* prev1=dummy;
    int prevPos=left;
    prevPos--;
    while(prevPos--){
    prev1=prev1->next;
    }
    ListNode* curr=prev1->next;
    ListNode* prev=prev1;
    ListNode* front=NULL;
    int req=right-left+1;
    while(curr && req>0){
    front=curr->next;
    curr->next=prev;
    prev=curr;
    curr=front;
    req--;
    }
   
    prev1->next->next=curr;
     prev1->next=prev;
    return dummy->next;
    }
};