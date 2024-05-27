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
    vector<int>ans;
    map<int,int>mp;
    private:
    void solve(TreeNode* root,int l){
        if(root==NULL)return;

        if(root->left)solve(root->left,l+1);
        if(root->right)solve(root->right,l+1);

        mp[l]=root->val;
    }
public:
    vector<int> rightSideView(TreeNode* root){
        solve(root,0);
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
        
    }
};