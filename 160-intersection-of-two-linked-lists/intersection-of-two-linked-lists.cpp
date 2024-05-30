/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        ListNode*a1=a,*b1=b;
        if(a==b)return a;
        while(a!=b){
            if(a==b)return a;
            a=a->next;
            b=b->next;
            if(a==b)return a;
            if(!a) a=b1;
            if(!b) b=a1;
            if(a==b)return a;
        }
        return NULL;    
    }
};