#include<iostream>
#include<vector>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

bool isValid(TreeNode* root, long long lower, long long upper) {
    if (root == nullptr) 
        return true;
    if (root->val <= lower || root->val >= upper) 
        return false;
    return isValid(root->left, lower, root->val) && isValid(root->right, root->val, upper);
}

bool isValidBST(TreeNode* root) {
    return isValid(root, LONG_MIN, LONG_MAX);
}

TreeNode* insertLevelOrder(vector<int>& arr, int i, int n) {
    TreeNode* root = nullptr;
    if (i < n && arr[i] != -1) {
        root = new TreeNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, 2 * i + 2, n);
    }
    return root;
}

int main(){
    // question should be in level order (NULL = -1)
    vector<int> question = {5, 1, 4, -1, -1, 3, 6};
    TreeNode* root = insertLevelOrder(question, 0, question.size());
    cout<<"This tree "<<(isValidBST(root) ? "a valid" : "an invalid")<<" BST"<<endl;

    return 0;
}
