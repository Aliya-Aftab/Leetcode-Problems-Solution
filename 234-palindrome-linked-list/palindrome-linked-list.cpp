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
        while(curr){
         ListNode* fut=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fut;
        }  
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next ){
            return true;
        }
        ListNode* curr=head;
        ListNode* prev=NULL;
        int count=0;
        while(curr){
            count++;
            curr=curr->next;
        }
        count/=2;
        curr=head;
        while(count--){
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        curr=reverse(curr, NULL);
        prev=head;
        while(prev){
            if(prev->val != curr->val){
                return false;
            }
            prev=prev->next;
            curr=curr->next;
        }
        return true;
    }
};