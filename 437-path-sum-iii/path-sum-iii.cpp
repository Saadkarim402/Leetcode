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
    long long ans=0;
    unordered_map<long long,int>mp;
    private:
    void solve(TreeNode*root,int tar,long long s){
        if(!root)return;

        s+=root->val;
        if(s==tar)ans++;
        if(mp.find(s-tar)!=mp.end())
        ans+=mp[s-tar];
        mp[s]++;
        solve(root->left,tar,s);
        solve(root->right,tar,s);
        mp[s]--;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        mp.clear();
        //if(targetSum==0)return 0;
        ans=0;
        solve(root,targetSum,0);
        return ans;
        
    }
};