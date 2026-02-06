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
    ListNode *mergeTwoList(ListNode *h1, ListNode *h2){
    if(!h1){
    return h2;
    }
    if(!h2){
    return h1;
    }
    if(h1->val<=h2->val){
    h1->next=mergeTwoList(h1->next, h2);
    return h1;
    }
    else{
    h2->next=mergeTwoList(h1, h2->next);
    return h2;
    }
    return NULL;
    }
    ListNode *merge(int start, int end, vector<ListNode*>&lists){
    if(start>end){
    return NULL;
    }
    if(start==end){
    return lists[start];
    }
    int mid=start+(end-start)/2;
    ListNode* left=merge(start, mid, lists);
   ListNode* right=merge(mid+1, end, lists);
    return mergeTwoList(left, right);
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size()==0)
    return NULL;
    return merge(0, lists.size()-1, lists);  
    }
};