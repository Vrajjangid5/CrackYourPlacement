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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val==p->val){
            return p;
            
        }
        if(root->val==q->val){
            return q;
            
        }
        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left==NULL and right==NULL){
            return NULL;
        }else if(left!=NULL and right==NULL){
            return left;
        }else if(left==NULL and right!=NULL){
            return right;
        }else{
            return root;
        }
    }
};
