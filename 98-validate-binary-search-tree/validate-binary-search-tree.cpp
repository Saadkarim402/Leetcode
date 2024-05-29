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
    bool solve(TreeNode*root,long long mini,long long maxi){
        if(!root)return true;
        if(root->val>mini&&root->val<maxi)
        return solve(root->left,mini,root->val)&&solve(root->right,root->val,maxi);
        else return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        long long  min=-1e18,max=1e18;
        return solve(root,min,max);

        
    }
};