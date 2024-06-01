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
    private:
    ListNode*merge(ListNode*l1,ListNode*l2){
        ListNode*ptr=new ListNode(-1);
        ListNode*cur=ptr;
        while(l1&&l2){
            if(l1->val>=l2->val){
                cur->next=l2;
                l2=l2->next;
            }
            else{
                cur->next=l1;
                l1=l1->next;
            }
            cur=cur->next;
        }
        if(l1){
            cur->next=l1;
            l1=l1->next;
        }
        if(l2){
            cur->next=l2;
            l2=l2->next;
        }
        return ptr->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode*slow=head,*fast=head,*temp=NULL;
        while(fast&&fast->next){
            temp=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        temp->next=NULL;
        ListNode*l1=sortList(head);
        ListNode*l2=sortList(slow);
        return merge(l1,l2);
    }
};