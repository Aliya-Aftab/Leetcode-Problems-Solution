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
    int steps=k-1;
    ListNode* curr1=head;
    ListNode* curr2=head;
    int cnt=0;
    while(curr1){
    cnt++;
    curr1=curr1->next;
    }
    cnt-=k;
    curr1=head;
    while(cnt--){
    curr1=curr1->next;
    }
    while(steps--){
    curr2=curr2->next;
    }
    int temp=curr1->val;
    curr1->val=curr2->val;
    curr2->val=temp;
    return head; 
    }
};