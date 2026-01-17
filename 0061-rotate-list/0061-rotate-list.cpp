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
    ListNode* rotateRight(ListNode* head, int k) {
    if(!head || !head->next){
    return head;
    }
    
    long long count=0;
    ListNode* temp=head;
    while(temp){
    count++;
    temp=temp->next;
    }
      k=k % count; 
      if(k==0){
    return head;
    }
      count-=k;
    temp=head;
    ListNode* prev; 
    while(count--){
    prev=temp;
    temp=temp->next;
    } 
    prev->next=NULL;
    ListNode* tail=temp;
    while(tail->next){
    tail=tail->next;
    }
    tail->next=head;
    head=temp;
    return head;
    }
};