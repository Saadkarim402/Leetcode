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
    int check(TreeNode* root, TreeNode* p, int t){
        while(root){
            if(root->val == t && root!=p)
                return 1;
            if(root->val < t)
                root= root->right;
            else
                root= root->left;
        }
        return 0;
    }
    

    void pre(TreeNode* root, TreeNode* p, int k, int &flag){
        if(p && !flag){
            flag= check(root, p, k-p->val);
            pre(root, p->left, k, flag);
            pre(root, p->right, k, flag);
        }
    }
public:
   bool findTarget(TreeNode* root, int k) {
        TreeNode* p= root;
        int flag= 0;
        pre(root, p, k, flag);
        return flag;
    }
};