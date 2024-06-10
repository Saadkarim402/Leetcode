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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    ListNode*find(ListNode*head){
        if(!head->next)return head;

        ListNode*slow=head,*fast=head,*prev=NULL;

        while(fast&&fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if (prev) {
            prev->next = nullptr;
        }
        return slow;
    }


    TreeNode*solve(ListNode*head){
        if(!head)return NULL;

        ListNode*mid=find(head);
        //cout<<mid->val<<endl;

        TreeNode*node=new TreeNode(mid->val);

        if (mid != head) { // To avoid infinite loop
            node->left = solve(head);
        }
        node->right=solve(mid->next);

        return node;

    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head);
    }
};