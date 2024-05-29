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
    TreeNode*solve(TreeNode*root){
        if(root->right==NULL)return root;
       return solve(root->right);
    }
    TreeNode*helper(TreeNode*root){
        // if one of the node doesnt exist
        if(!root->left) return root->right;
        if(!root->right) return root->left;
        // if both exist 
        TreeNode*left=root->left;
        TreeNode*right=root->right;
        //find the rightmost ele of the left tree
        TreeNode*rmost=solve(left);
        rmost->right=right;
        return left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
        if(root->val==key) return helper(root);
        TreeNode*dummy=root;

        while(root!=NULL){
            if(root->val>key){
            if(root->left&&root->left->val==key){
                root->left=helper(root->left);
                break;
            }
            else root=root->left;
            }
            else{
                if(root->right&&root->right->val==key){
                    root->right=helper(root->right);
                    break;
                }
                else root=root->right;
            }
        }
        return dummy;
        
    }
};