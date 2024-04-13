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
    void solve(TreeNode* root,int c,int &ans){
        if(!root){
            return ;
        }
        c=(10*c)+root->val;
        if(!root->left&&!root->right){
            ans+=c;
            return;
        }
        solve(root->left,c,ans);
        solve(root->right,c,ans);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans=0,l=0;
        solve(root,0,ans);
        return ans;
        
    }
};