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
    ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* first=new ListNode(0);
    first->next=head;
    head=first;
    ListNode* second, *curr, *prev, *front;
    int x;
    while(first->next){
    int count=0;
    ListNode* temp=first->next;
    while(temp && count<k){
    count++;
    temp=temp->next;
    }
    if(count<k){
    break;
    }
    x=k;
    prev=first;
    second=first->next;
    curr=first->next;
    while(x && curr){
    front=curr->next;
    curr->next=prev;
    prev=curr;
    curr=front;
    x--;
    }
    first->next=prev;
    second->next=curr;
    first=second;
    }
    first=head;
    head=head->next;
    delete first;
    return head;
    }
};