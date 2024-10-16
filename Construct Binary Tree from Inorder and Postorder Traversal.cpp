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
    // Find position of a node in inorder traversal
    int position(int data, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            if (data == inorder[i]) {
                return i;
            }
        }
        return -1;
    }

    // Recursive function to build the tree
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inS, int inE, int &posI) {
        if (posI < 0 || inS > inE) {
            return nullptr;
        }

        // Create the root node with the current value in postorder traversal
        int data = postorder[posI--];
        TreeNode* root = new TreeNode(data);

        // Find the position of this value in the inorder traversal
        int pos = position(data, inorder);

        // Construct the right subtree first, then the left subtree
        root->right = solve(inorder, postorder, pos + 1, inE, posI);
        root->left = solve(inorder, postorder, inS, pos - 1, posI);

        return root;
    }

    // Function to initiate tree building
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inS = 0;
        int inE = inorder.size() - 1;
        int posI = postorder.size() - 1;
        return solve(inorder, postorder, inS, inE, posI);
    }
};
