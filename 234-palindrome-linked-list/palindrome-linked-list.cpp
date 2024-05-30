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
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head,*fast=head;
        if(slow->next==NULL)return true;
        if(fast->next->next==NULL){
            if(slow->val!=slow->next->val){
                return false;
            }
            return true;
        }
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*cur=slow,*prv=NULL,*forw=NULL;
        while(cur){
            forw=cur->next;
            cur->next=prv;
            prv=cur;
            cur=forw;
        }
        while(prv){
            if(prv->val!=head->val){
                return false;
            }
            prv=prv->next;
            head=head->next;
        }
        return true;

        
    }
};