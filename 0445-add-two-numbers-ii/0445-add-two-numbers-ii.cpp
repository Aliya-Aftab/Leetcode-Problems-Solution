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
    ListNode* reverse(ListNode* curr, ListNode* prev){
    // base case
    if(!curr){
    return prev;
    }
    ListNode* fut=curr->next;
    curr->next=prev;
    return reverse(fut, curr);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    l1=reverse(l1, NULL);
    l2=reverse(l2, NULL);
    ListNode* curr1=l1;
    ListNode* curr2=l2;
    int sum=0, carry=0;
    ListNode* dummy=new ListNode(0);
    ListNode* tail=dummy;
    while(curr1 || curr2 || carry){
    sum=carry;
    if(curr1){
    sum+=curr1->val;
    curr1=curr1->next;
    }
    if(curr2){
    sum+=curr2->val;
    curr2=curr2->next;
    }
    tail->next=new ListNode(sum%10);
    tail=tail->next;
    carry=sum/10;
    }
    ListNode* ans=reverse(dummy->next, NULL);
    delete dummy;
    return ans;
    }
};