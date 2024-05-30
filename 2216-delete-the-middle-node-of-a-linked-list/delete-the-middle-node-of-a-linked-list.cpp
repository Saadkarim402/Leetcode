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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head||!head->next)return NULL;
        if(head->next->next==NULL){
            head->next=head->next->next;
            return head;
        }

        ListNode*slow=head,*fast=head->next->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*del=slow->next;
        slow->next=slow->next->next;
        delete del;
        return head;   
    }
};