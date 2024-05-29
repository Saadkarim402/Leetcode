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
    int solve(TreeNode*root){
         //if(!root)return 0;
        if(root->left==NULL&&root->right==NULL)return 0;

        int l=1e9,r=1e9;
        if(root->left!=NULL){
            l=solve(root->left);
        }
        if(root->right!=NULL){
            r=solve(root->right);
        }

        return min(l,r)+1;
    }
public:
    int minDepth(TreeNode* root) {
        // if(root->left==NULL)root=root->right;
        // if(root->right==NULL)root=root->left;
        if(!root)return 0;
      return  solve(root)+1;

        
    }
};