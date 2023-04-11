#include <iostream>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        val = data;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
public:
    BinaryTree() {
        root = NULL;
    }
    void insert(int data) {
        root = insertHelper(root, data);
    }
    void inOrderTraversal() {
        inOrderTraversalHelper(root);
    }
    void preOrderTraversal() {
        preOrderTraversalHelper(root);
    }
    void postOrderTraversal() {
        postOrderTraversalHelper(root);
    }
private:
    TreeNode* root;
    TreeNode* insertHelper(TreeNode* node, int data) {
        if(node == NULL) {
            node = new TreeNode(data);
        } else if(data <= node->val) {
            node->left = insertHelper(node->left, data);
        } else {
            node->right = insertHelper(node->right, data);
        }
        return node;
    }
    void inOrderTraversalHelper(TreeNode* node) {
        if(node == NULL) {
            return;
        }
        inOrderTraversalHelper(node->left);
        cout << node->val << " ";
        inOrderTraversalHelper(node->right);
    }
    void preOrderTraversalHelper(TreeNode* node) {
        if(node == NULL) {
            return;
        }
        cout << node->val << " ";
        preOrderTraversalHelper(node->left);
        preOrderTraversalHelper(node->right);
    }
    void postOrderTraversalHelper(TreeNode* node) {
        if(node == NULL) {
            return;
        }
        postOrderTraversalHelper(node->left);
        postOrderTraversalHelper(node->right);
        cout << node->val << " ";
    }
};

int main() {
    BinaryTree tree;
    tree.insert(3);
    tree.insert(1);
    tree.insert(2);
    tree.insert(5);
    tree.insert(4);
    tree.inOrderTraversal(); // Output: 1 2 3 4 5
    tree.preOrderTraversal(); // Output: 3 1 2 5 4
    tree.postOrderTraversal(); // Output: 2 1 4 5 3
    return 0;
}
