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
    if(!head){
    return NULL;
    }
    // copying simple list w/o random pointer
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
    
    // inserting the nodes of cloned linked list bw original linked list nodes
    Node* curr1=head;
    Node* curr2=headCopy;
    Node* front1, *front2;
    while(curr1){
    front1=curr1->next;
    front2=curr2->next;
    curr1->next=curr2;
    curr2->next=front1;
    curr1=front1;
    curr2=front2;
    }

    // assigning random pointer 
    // curr1 always lying on original nodes
    // curr2 always lying on cloned nodes
    curr1=head;
    while(curr1){
    curr2=curr1->next;
    if(curr1->random){
    curr2->random=curr1->random->next;
    }
    curr1=curr2->next;
    }
    // separating the lists
    curr1=head;
    while(curr1->next){
    front1=curr1->next;
    curr1->next=front1->next;
    curr1=front1;
    }
    return headCopy;
    }
};