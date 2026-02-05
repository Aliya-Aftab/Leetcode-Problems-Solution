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
    if(!curr){
    return prev;
    }
    ListNode* future=curr->next;
    curr->next=prev;
    return reverse(future, curr);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // l1=reverse(l1, NULL);
    // l2=reverse(l2, NULL);
    ListNode* curr1=l1;
    ListNode* curr2=l2 ;
    ListNode* newHead=new ListNode(0);
    ListNode* tail=newHead;

    int sum=0;
    int carry=0;
    while(curr1 && curr2){
    sum=curr1->val + curr2->val + carry;
    tail->next=new ListNode (sum%10);
    tail=tail->next;
    curr1=curr1->next;
    curr2=curr2->next;
    carry=sum/10;
    }

    while(curr1){
    sum=curr1->val+carry;
    tail->next=new ListNode(sum%10);
    tail=tail->next;
    curr1=curr1->next;
    carry=sum/10;
    }

    while(curr2){
    sum=curr2->val+carry;
    tail->next=new ListNode(sum%10);
    tail=tail->next;
    curr2=curr2->next;
    carry=sum/10;
    }

    while(carry){
    tail->next=new ListNode(carry%10);
    tail=tail->next;
    carry=carry/10;
    }
    // newHead=reverse(newHead->next, NULL);
    return newHead->next;
    }
};