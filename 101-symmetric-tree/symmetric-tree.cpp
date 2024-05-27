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
    bool solve(TreeNode* root1,TreeNode* root2){
        if(root1==NULL||root2==NULL){
            return root1==root2;
        }
        bool c=root1->val==root2->val;
        bool l=solve(root1->left,root2->right);
        bool r=solve(root1->right,root2->left);
        return (c&&l&&r);

    }
public:
    bool isSymmetric(TreeNode* root) {
        return solve(root,root);
        
    }
};