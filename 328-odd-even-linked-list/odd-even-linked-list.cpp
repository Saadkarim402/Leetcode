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
    ListNode* oddEvenList(ListNode* head) {
        //base cases
        if(!head)return NULL;
        if(head->next==NULL||head->next==NULL)return head;

        ListNode*p1=head,*p2=head->next,*p=p2;
        while(p1&&p2&&p1->next&&p2->next){
            p1->next=p2->next;
            p1=p1->next;
            p2->next=p1->next;
            p2=p2->next;
        }
        p1->next=p;
        return head;

        
    }
};