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
    TreeNode*solve(TreeNode*root,int tar){
        if(!root)return NULL ;

        if(root->val==tar)return root;

        if(root->val<tar){
           return solve(root->right,tar);
        }
        else{
          return  solve(root->left,tar);
        }
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        return solve(root,val);
        
    }
};