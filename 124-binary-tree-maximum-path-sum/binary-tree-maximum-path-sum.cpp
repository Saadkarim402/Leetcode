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
    int solve(TreeNode* root,int &ans){
        if(!root){
            return 0;
        }
        int l=max(0,solve(root->left,ans));
        int r=max(0,solve(root->right,ans));
        ans=max(ans,l+r+root->val);
        return root->val+max(l,r);

    }
public:
    int maxPathSum(TreeNode* root) {
        int ans=-1e9;
        solve(root,ans);
        return ans;
        
    }
};