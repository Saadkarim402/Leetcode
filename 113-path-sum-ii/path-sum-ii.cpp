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
    vector<vector<int>>v;
    private:
    void solve(TreeNode* root,int k,vector<int>temp,int c){
        if(!root){
            return;
        }
        c+=root->val;
        temp.push_back(root->val);
        if(c==k&&(!root->left&&!root->right)){
                v.push_back(temp);
        }
        solve(root->left,k,temp,c);
        solve(root->right,k,temp,c);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        solve(root,targetSum,temp,0);
        return v;

        
    }
};