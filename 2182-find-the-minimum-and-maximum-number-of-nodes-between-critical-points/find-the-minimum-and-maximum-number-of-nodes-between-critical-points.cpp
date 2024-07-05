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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode*prev=head;
        head=head->next;
        vector<int>v;
        int i=1;
        while(head->next){
            ListNode*forw=head->next;
            //local maximan
            if(forw->val<head->val&&head->val>prev->val){
                v.push_back(i);
            }
            if(forw->val>head->val&&head->val<prev->val){
                v.push_back(i);
            }
            i++;
            prev=head;
            head=head->next;
        }
        if(v.size()<2)return {-1,-1};
        int maxi=-1e9,mini=1e9;
        maxi=v[v.size()-1]-v[0];
        for(int i=0;i<v.size()-1;i++){
            mini=min(mini,v[i+1]-v[i]);
        }
        return {mini,maxi};
    }
};