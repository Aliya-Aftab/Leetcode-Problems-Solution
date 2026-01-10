/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    Node* headCopy=new Node(0);
    Node* tailCopy=headCopy;
    Node* temp=head;
    while(temp){
    tailCopy->next=new Node(temp->val);
    tailCopy=tailCopy->next;
    temp=temp->next;
    }
    Node* dummydlt=headCopy;
    headCopy=headCopy->next; 
    tailCopy=headCopy;
    temp=head;
    delete dummydlt;
    unordered_map<Node*, Node*>mp;
    while(temp){
    mp[temp]=tailCopy;
    temp=temp->next;
    tailCopy=tailCopy->next;
    }
    // reset
    temp=head;
    tailCopy=headCopy;
    while(temp){
    tailCopy->random=mp[temp->random];
    tailCopy=tailCopy->next;
    temp=temp->next;
    }
    
    return headCopy;
    }
};