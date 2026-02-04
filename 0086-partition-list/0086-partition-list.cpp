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
    ListNode* partition(ListNode* head, int x) {
    ListNode* lessSt=new ListNode(1000);
    ListNode* moreSt=new ListNode(1000);
    ListNode* less=lessSt;
    ListNode* more=moreSt;
    ListNode* curr=head;
    while(curr){
    if(curr->val<x){
    less->next=curr;
    less=less->next;
    }
    else{
    more->next=curr;
    more=more->next;
    }
    curr=curr->next;
    } 
    less->next=moreSt->next;
    more->next=NULL;
    return lessSt->next;
    }
};