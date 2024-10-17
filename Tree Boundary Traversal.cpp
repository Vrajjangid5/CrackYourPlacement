
class Solution {
public:
    void solveLeft(Node* root, vector<int>& ans){
        if(root->left || root->right) ans.push_back(root->data);
        if(root->left) solveLeft(root->left, ans);
        else if(root->right) solveLeft(root->right, ans);
    }
    void solveRight(Node* root, vector<int>& ans){
        if(root->left || root->right) ans.push_back(root->data);
        if(root->right) solveRight(root->right, ans);
        else if(root->left) solveRight(root->left, ans);
    }
    void solveleaf(Node* root, vector<int>& ans){
        if(!root->left && !root->right) ans.push_back(root->data);
        if(root->left) solveleaf(root->left, ans);
        if(root->right) solveleaf(root->right, ans);
    }
    vector <int> boundary(Node *root){
        //Your code here
        vector<int>left, right, leaf, ans;
        if(root->left || root->right) ans.push_back(root->data);
        if(root->left) solveLeft(root->left, left);
        if(root->right) solveRight(root->right, right);
        solveleaf(root, leaf);
        reverse(right.begin(), right.end());
        for(auto i:left) ans.push_back(i);
        for(auto i:leaf) ans.push_back(i);
        for(auto i:right) ans.push_back(i);
        return ans;
    }
};
