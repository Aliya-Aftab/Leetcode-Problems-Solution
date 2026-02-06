/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int cnt1=0;
    int cnt2=0;
    ListNode* curr1=headA;
    ListNode* curr2=headB;
    while(curr1){
    cnt1++;
    curr1=curr1->next;
    } 
    while(curr2){
    cnt2++;
    curr2=curr2->next;
    }
    curr1=headA;
    curr2=headB;
    while(cnt1>cnt2){
    curr1=curr1->next;
    cnt1--;
    }
    while(cnt2> cnt1){
    curr2=curr2->next;
    cnt2--;
    }
    while(curr1!=curr2){
    curr1=curr1->next;
    curr2=curr2->next;
    }
    if(!curr1){
    return NULL;
    }
    return curr1;
    }
};