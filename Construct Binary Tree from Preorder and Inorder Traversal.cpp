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

    int GetPos(int data,vector<int>&inorder){
        for(int i=0;i<inorder.size();i++){
            if(data==inorder[i]){
                return i;
            }
        }
        return -1;
    }


    TreeNode*solve(vector<int>& preorder, vector<int>& inorder,int &preIndex,int inStart,int inEnd){
        if(preIndex==preorder.size() || inStart>inEnd){
            return NULL;
        }
        int data=preorder[preIndex++];
        TreeNode*root=new TreeNode(data);
        int pos=GetPos(data,inorder);
        root->left=solve(preorder,inorder,preIndex,inStart,pos-1);
        root->right=solve(preorder,inorder,preIndex,pos+1,inEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex=0;
        int inStart=0;
        int inEnd=inorder.size();
        return solve(preorder,inorder,preIndex,inStart,inEnd);
    }
};
