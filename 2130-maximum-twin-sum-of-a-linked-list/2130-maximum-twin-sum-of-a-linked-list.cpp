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
    int pairSum(ListNode* head) {
    int count=0;
    ListNode* curr=head;
    while(curr){
    count++;
    curr=curr->next;
    } 
    count/=2;
    ListNode* prev=NULL;
    curr=head;
    while(count--){
    prev=curr;
    curr=curr->next;
    } 
    prev->next=NULL;
    ListNode* future=curr->next;
    prev=NULL;
    while(curr){
    future=curr->next;
    curr->next=prev;
    prev=curr;
    curr=future;
    }
    int maxSum=INT_MIN;
    ListNode* head1=head;
    ListNode* head2=prev;
    while(head1 && head2){
    int sum=head1->val + head2->val;
    if(sum>maxSum){
    maxSum=sum;
    }
    head1=head1->next;
    head2=head2->next;
    } 
    return maxSum; 
    }
};