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
    if(!head || !head->next){
    return head;
    }
    ListNode* first=new ListNode(0);
    first->next=head;
    head=first;
    ListNode* curr, *prev, *second, *front;
    int x;
    while(first->next){
    prev=first;
    curr=first->next;
    second=first->next;
    x=k;
    ListNode* temp=curr;
    int cnt=0;

    while(temp && cnt<k){
    cnt++;
    temp=temp->next;
    }
    if(cnt<k){
    break;
    }
   
    while(curr && x){
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