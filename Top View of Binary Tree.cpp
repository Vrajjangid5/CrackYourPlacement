class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
       map<int, int> mp;  // Stores the top view nodes with their horizontal distance as key
    queue<pair<Node*, int>> q;  // Queue stores pairs of Node and its horizontal distance
    int hd = 0;  // Initialize horizontal distance
    q.push(make_pair(root, hd));  // Push root node with horizontal distance 0

    while (!q.empty()) {
        pair<Node*, int> p = q.front();
        q.pop();
        Node* temp = p.first;
        int dataa = p.second;

        // If horizontal distance is not present in map, add it (first occurrence is the top view)
        if (mp.find(dataa) == mp.end()) {
            mp[dataa] = temp->data;
        }

        // Push left child with horizontal distance -1
        if (temp->left) {
            q.push(make_pair(temp->left, dataa - 1));
        }

        // Push right child with horizontal distance +1
        if (temp->right) {
            q.push(make_pair(temp->right, dataa + 1));
        }
    }

    // Collect the top view nodes in order of their horizontal distance
    vector<int> ans;
    for (auto it : mp) {
        ans.push_back(it.second);
    }
    
    return ans;
    }

};
