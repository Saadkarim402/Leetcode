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
    TreeNode*solve(vector<int>&v,int l,int r){
        if(l>r)return NULL;
        int mid=(l+r)/2;
        TreeNode*node=new TreeNode(v[mid]);

        node->left=solve(v,l,mid-1);
        node->right=solve(v,mid+1,r);
        
        return node;

    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);

        
    }
};