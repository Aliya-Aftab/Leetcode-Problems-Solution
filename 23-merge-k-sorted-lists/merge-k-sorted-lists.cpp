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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; 
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;
        for(ListNode* list : lists){
            if(list != NULL){
                pq.push(list);
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(!pq.empty()){
            ListNode* smallest = pq.top();
            pq.pop();
            tail->next = smallest;
            tail = tail->next;
            if(smallest->next){
                pq.push(smallest->next);
            }
        }
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};