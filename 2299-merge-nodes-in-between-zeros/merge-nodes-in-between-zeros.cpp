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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*dummy=new ListNode(-1);
        ListNode*d1=dummy;
        head=head->next;
        int cur=0;
                cout<<cur<<endl;

        while(head){
            if(head->val==0){
                dummy->next=new ListNode(cur);
                dummy=dummy->next;
                head=head->next;
                cur=0;
            }
            else{

                cur+=head->val;
                head=head->next;
            }
        }
        return d1->next;

    }
};