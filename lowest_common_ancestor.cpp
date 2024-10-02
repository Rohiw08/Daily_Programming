#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insertLevelOrder(vector<int>& arr, int i, int n) {
    TreeNode* root = nullptr;
    if (i < n && arr[i] != -1) {
        root = new TreeNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

void printTree(TreeNode* root) {
    if (!root) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) return root;

    return left ? left : right;
}

TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    if (left) return left;
    return findNode(root->right, val);
}

int main() {
    // Ex Input: [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]
    vector<int> arr = {3, 5, 1, 6, 2, 0, 8, -1, -1, 7, 4};
    
    TreeNode* root = insertLevelOrder(arr, 0, arr.size());

    cout << "Binary Tree: ";
    printTree(root);
    
    // Test case: Find the LCA of nodes with values 5 and 4
    TreeNode* p = findNode(root, 5);
    TreeNode* q = findNode(root, 1);
    
    TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca)
        cout<<"LCA of "<<p -> val<<" and "<<q -> val<<" is : "<<lca -> val<< endl;
    else
        cout << "No LCA found" << endl;

    return 0;
}

