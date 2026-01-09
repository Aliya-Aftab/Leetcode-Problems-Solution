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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    int count=0;
    ListNode* temp=head;
    while(temp){
    count++;
    temp=temp->next;
    }
    if(n==count){
    ListNode* newHead=head->next;
    delete head;
    return newHead;
    }
    temp=head;   
    for(int i=0;i<count-n-1;i++){
    temp=temp->next;
    }
    ListNode *del=temp->next;
  
    temp->next=del->next;
      delete del;
    return head;
    }
};