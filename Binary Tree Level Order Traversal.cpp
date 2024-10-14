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


    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*> q;
        if(!root) return ans;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            for(int i=0;i<n;i++){
                TreeNode* tem=q.front();
                q.pop();
                temp.push_back(tem->val);
                if(tem->left){
                    q.push(tem->left);
                }
                if(tem->right){
                    q.push(tem->right);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
