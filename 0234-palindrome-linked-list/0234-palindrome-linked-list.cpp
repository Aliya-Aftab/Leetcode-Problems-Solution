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
    bool isPalindrome(ListNode* head) {
    if(head->next==NULL){
    return 1;
    }
    int count=0;
    ListNode* temp=head;
    while(temp){
    count++;
    temp=temp->next;
    }  
    count/=2;
    temp=head;
    ListNode* prev=NULL;
    while(count--){
    prev=temp;
    temp=temp->next;
    }
    prev->next=NULL;
    ListNode* future=NULL;
    prev=NULL;
    while(temp){
    future=temp->next;
    temp->next=prev;
    prev=temp;
    temp=future;
    }
    ListNode* head1=head;
    ListNode* head2=prev;
    while(head1){
    if(head1->val!=head2->val){
    return false;
    }
    head1=head1->next;
    head2=head2->next;
    }
    return true;
    }
};