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
        //create copy node in btw nodes
        Node*temp=head;
        while(temp){
            Node*newnode=new Node(temp->val);
            newnode->next=temp->next;
            temp->next=newnode;
            temp=temp->next->next;
        }
        //connnexting random pointers
        temp=head;
        while(temp){
            Node*copy=temp->next;
            if(temp->random){
                copy->random=temp->random->next;
            }
            else{
                copy->random=temp->random;
            }
            temp=temp->next->next;
        }
        //connecting the next pounters;
        temp=head;
        Node*dummy=new Node(-1);
        Node*res=dummy;
        while(temp){
            res->next=temp->next;
            res=res->next;

            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummy->next;


        
    }
};