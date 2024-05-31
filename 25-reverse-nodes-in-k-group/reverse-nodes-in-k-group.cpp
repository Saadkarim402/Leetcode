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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||k<=1)return head;

        ListNode*prev=NULL,*cur=head,*forw=NULL;
        int c=0;
        ListNode*d=cur;
        while(d&&c<k){
            c++;
            d=d->next;
        }
        if(c==k){
            int c=0;
            while(cur&&c<k){
             forw=cur->next;
             cur->next=prev;
             prev=cur;
             cur=forw;
             c++;
            }
        }
        else {cout<<c<<endl;return head;}
        if(forw){
            head->next=reverseKGroup(forw,k);
        }
        return prev;
        
    }
};