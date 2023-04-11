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

class BinarySearchTree {
public:
    BinarySearchTree() {
        root = NULL;
    }
    void insert(int data) {
        root = insertHelper(root, data);
    }
    bool search(int data) {
        return searchHelper(root, data);
    }
    void remove(int data) {
        root = removeHelper(root, data);
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
    bool searchHelper(TreeNode* node, int data) {
        if(node == NULL) {
            return false;
        } else if(node->val == data) {
            return true;
        } else if(data <= node->val) {
            return searchHelper(node->left, data);
        } else {
            return searchHelper(node->right, data);
        }
    }
    TreeNode* removeHelper(TreeNode* node, int data) {
        if(node == NULL) {
            return NULL;
        } else if(data < node->val) {
            node->left = removeHelper(node->left, data);
        } else if(data > node->val) {
            node->right = removeHelper(node->right, data);
        } else {
            // Case 1: No child
            if(node->left == NULL && node->right == NULL) {
                delete node;
                node = NULL;
            }
            // Case 2: One child
            else if(node->left == NULL) {
                TreeNode* temp = node;
                node = node->right;
                delete temp;
            } else if(node->right == NULL) {
                TreeNode* temp = node;
                node = node->left;
                delete temp;
            }
            // Case 3: Two children
            else {
                TreeNode* temp = findMin(node->right);
                node->val = temp->val;
                node->right = removeHelper(node->right, temp->val);
            }
        }
        return node;
    }
    TreeNode* findMin(TreeNode* node) {
        while(node->left != NULL) {
            node = node->left;
        }
        return node;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);
    cout << bst.search(7) << endl; // Output: 1 (true)
    bst.remove(7);
    cout << bst.search(7) << endl; // Output: 0 (false)
    return 0;
}
