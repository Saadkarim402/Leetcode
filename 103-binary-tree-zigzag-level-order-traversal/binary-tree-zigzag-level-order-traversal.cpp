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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        bool lr=true;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int>temp(sz);
            // cout<<sz<<endl;
            for(int i=0;i<sz;i++){
                int ind=i;
                if(!lr) ind=sz-i-1;
                TreeNode* node=q.front();
                q.pop();
                temp[ind]=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            lr=!lr;
            ans.push_back(temp);
        }
        return ans;
    }
};