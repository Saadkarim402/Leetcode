/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
    void solve(unordered_map<TreeNode*,TreeNode*>&par,TreeNode*root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                par[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                par[node->right]=node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>par;
        solve(par,root);
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int cur=0;
        while(!q.empty()){
            int sz=q.size();
            if(cur==k)break;
            cur++;
            for(int i=0;i<sz;i++){
                TreeNode*node=q.front();
                q.pop();
                if(node->left&&!vis[node->left]){
                    vis[node->left]=true;
                    q.push(node->left);
                }
                if(node->right&&!vis[node->right]){
                    vis[node->right]=true;
                    q.push(node->right);
                }
                if(par[node]&&!vis[par[node]]){
                    vis[par[node]]=true;
                    q.push(par[node]);
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int k=q.front()->val;
            q.pop();
            ans.push_back(k);
        }
        return ans;
    }
};