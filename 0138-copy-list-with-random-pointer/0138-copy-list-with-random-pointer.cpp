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
    Node* find(Node* curr1, Node* curr2, Node* X){
    if(X==NULL){
    return NULL;
    }
    while(curr1!=X){
    curr1=curr1->next;
    curr2=curr2->next;
    }
    return curr2;
    }
    Node* copyRandomList(Node* head) {
    Node* headCopy=new Node(0);
    Node* tailCopy=headCopy;
    Node* temp=head;
    while(temp){
    tailCopy->next=new Node(temp->val);
    tailCopy=tailCopy->next;
    temp=temp->next;
    }
    headCopy=headCopy->next; 
    tailCopy=headCopy;
    temp=head;
    tailCopy=headCopy;
    while(temp){
    tailCopy->random=find(head, headCopy,temp->random );
    tailCopy=tailCopy->next;
    temp=temp->next;
    }
        return headCopy;

    }
};