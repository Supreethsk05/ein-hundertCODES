#include <iostream>
using namespace std;

struct Node {
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int key) {
        this->key = key;
        height = 1;
        left = right = nullptr;
    }
};

class AVLTree {
    Node* root;

    int height(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int balanceFactor(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    void updateHeight(Node* node) {
        node->height = 1 + max(height(node->left), height(node->right));
    }

    Node* rotateRight(Node* node) {
        Node* leftChild = node->left;
        Node* leftRightChild = leftChild->right;

        // Perform rotation
        leftChild->right = node;
        node->left = leftRightChild;

        // Update heights
        updateHeight(node);
        updateHeight(leftChild);

        return leftChild;
    }

    Node* rotateLeft(Node* node) {
        Node* rightChild = node->right;
        Node* rightLeftChild = rightChild->left;

        // Perform rotation
        rightChild->left = node;
        node->right = rightLeftChild;

        // Update heights
        updateHeight(node);
        updateHeight(rightChild);

        return rightChild;
    }

    Node* rebalance(Node* node) {
        // Update height
        updateHeight(node);

        // Check balance factor
        int bf = balanceFactor(node);

        // Left-left case
        if (bf > 1 && balanceFactor(node->left) >= 0) {
            return rotateRight(node);
        }

        // Right-right case
        if (bf < -1 && balanceFactor(node->right) <= 0) {
            return rotateLeft(node);
        }

        // Left-right case
        if (bf > 1 && balanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right-left case
        if (bf < -1 && balanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node* insertUtil(Node* node, int key) {
        if (node == nullptr) {
            return new Node(key);
        }
        if (key < node->key) {
            node->left = insertUtil(node->left, key);
        } else if (key > node->key) {
            node->right = insertUtil(node->right, key);
        } else {
            return node;
        }

        return rebalance(node);
    }

    Node* findMinNode(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteUtil(Node* node, int key) {
        if (node == nullptr) {
            return node;
        }
        if (key < node->key) {
            node->left = deleteUtil(node->left, key);
        } else if (key > node->key) {
            node->right = deleteUtil(node->right, key);
        } else {
            if (node->left == nullptr || node->right == nullptr) {
                Node* temp = node->left ?
            node->left : node->right;
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            Node* temp = findMinNode(node->right);
            node->key = temp->key;
            node->right = deleteUtil(node->right, temp->key);
        }
    }
    if (node == nullptr) {
        return node;
    }

    return rebalance(node);
}

void inorderUtil(Node* node) {
    if (node == nullptr) {
        return;
    }
    inorderUtil(node->left);
    cout << node->key << " ";
    inorderUtil(node->right);
}
public:
AVLTree() {
root = nullptr;
}

void insert(int key) {
    root = insertUtil(root, key);
}

void deleteKey(int key) {
    root = deleteUtil(root, key);
}

void inorder() {
    inorderUtil(root);
    cout << endl;
}
};

int main() {
AVLTree tree;tree.insert(10);
tree.insert(20);
tree.insert(30);
tree.insert(40);
tree.insert(50);
tree.insert(25);

cout << "Inorder traversal of the AVL tree: ";
tree.inorder();

tree.deleteKey(30);

cout << "Inorder traversal of the AVL tree after deleting 30: ";
tree.inorder();

return 0;
}