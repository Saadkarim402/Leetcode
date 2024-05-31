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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode*slow=head,*fast=head;
        ListNode*l=head;
        if(!head||!head->next)return head;

        int c=0;
        while(l){
            l=l->next;
            c++;
        }
        for(int i=0;i<(k%c);i++){
            fast=fast->next;
        }
        if(fast==NULL||(k%c)==0){
            return head;
        }
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode*rev=slow->next,*rev1=slow->next;
        slow->next=NULL;
        while(rev->next){
            rev=rev->next;
        }
        rev->next=head;
        head=rev1;
        return head;

        
    }
};