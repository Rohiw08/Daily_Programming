#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Helper function to check mirror symmetry
bool isMirror(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    
    return (left->val == right->val) && 
           isMirror(left->left, right->right) && 
           isMirror(left->right, right->left);
}

// Function to check if a binary tree is symmetric
bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

// Function to create a binary tree from a vector
TreeNode* createBinaryTree(const vector<int>& values) {
    if (values.empty()) return nullptr;
    
    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    for (int i = 1; i < values.size(); i += 2) {
        TreeNode* current = q.front();
        q.pop();
        
        if (i < values.size() && values[i] != -1) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        
        if (i + 1 < values.size() && values[i + 1] != -1) {
            current->right = new TreeNode(values[i + 1]);
            q.push(current->right);
        }
    }
    
    return root;
}

int main() {
    vector<int> testCases = {1, 2, 2, 3, 4, 4, 3};
    TreeNode* root = createBinaryTree(testCases);
    
    bool result = isSymmetric(root);
    cout << "Output: " << (result ? "true" : "false") << endl;
    
    return 0;
}
