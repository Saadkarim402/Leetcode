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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>>p=q.front();
            TreeNode* node=p.first,first;
            int vlvl=p.second.first;
            int hlvl=p.second.second;
            q.pop();
            mp[vlvl][hlvl].insert(node->val);
            if(node->left!=NULL){
                q.push({node->left,{vlvl-1,hlvl+1}});
            }
            if(node->right!=NULL){
                q.push({node->right,{vlvl+1,hlvl+1}});
            }
        }
        for(auto it:mp){
            vector<int>temp;
            for(auto j:it.second){
                for(auto i:j.second){
                    temp.push_back(i);
                }
            }
            ans.push_back(temp);
        }
        return ans;   
    }
};