#pragma once


#include <iostream>

struct NodeSplay {
    float value;
    NodeSplay* left;
    NodeSplay* right;
};

struct SplayTree {
    NodeSplay* root;
    std::string tipo = "ÁRBOL SPLAY";
    bool listo = false;

    SplayTree() {
        root = nullptr;
    }

    void insert(float value) {
        insertNode(root, value);
    }

    int countNodes() {
        return countNodesRecursive(root);
    }

    float getSum() {
        return getSumRecursive(root);
    }

    void deleteLeftmostNode() {
        deleteLeftmostNodeRecursive(root);
    }

    void deleteNodes(int n) {
        deleteMultipleNodes(n);
    }

private:
    NodeSplay* createNode(float value) {
        NodeSplay* newNode = new NodeSplay;
        newNode->value = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    void splay(NodeSplay*& root, float value) {
        if (root == nullptr || root->value == value)
            return;

        if (value < root->value) {
            if (root->left == nullptr)
                return;

            if (value < root->left->value) {
                // Zig-Zig (left-left)
                splay(root->left->left, value);
                root = rotateRight(root);
            }
            else if (value > root->left->value) {
                // Zig-Zag (left-right)
                splay(root->left->right, value);
                if (root->left->right != nullptr)
                    root->left = rotateLeft(root->left);
            }

            if (root->left != nullptr)
                root = rotateRight(root);
        }
        else if (value > root->value) {
            if (root->right == nullptr)
                return;

            if (value < root->right->value) {
                // Zag-Zig (right-left)
                splay(root->right->left, value);
                if (root->right->left != nullptr)
                    root->right = rotateRight(root->right);
            }
            else if (value > root->right->value) {
                // Zag-Zag (right-right)
                splay(root->right->right, value);
                root = rotateLeft(root);
            }

            if (root->right != nullptr)
                root = rotateLeft(root);
        }
    }

    NodeSplay* rotateRight(NodeSplay* node) {
        NodeSplay* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        return newRoot;
    }

    NodeSplay* rotateLeft(NodeSplay* node) {
        NodeSplay* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        return newRoot;
    }

    void insertNode(NodeSplay*& root, float value) {
        if (root == nullptr) {
            root = createNode(value);
            return;
        }

        splay(root, value);

        if (value < root->value) {
            NodeSplay* newNode = createNode(value);
            newNode->left = root->left;
            newNode->right = root;
            root->left = nullptr;
            root = newNode;
        }
        else if (value > root->value) {
            NodeSplay* newNode = createNode(value);
            newNode->left = root;
            newNode->right = root->right;
            root->right = nullptr;
            root = newNode;
        }
    }

    int countNodesRecursive(NodeSplay* root) {
        if (root == nullptr)
            return 0;

        return 1 + countNodesRecursive(root->left) + countNodesRecursive(root->right);
    }

    float getSumRecursive(NodeSplay* root) {
        if (root == nullptr)
            return 0.0f;

        return root->value + getSumRecursive(root->left) + getSumRecursive(root->right);
    }

    void deleteLeftmostNodeRecursive(NodeSplay*& root) {
        if (root == nullptr)
            return;

        if (root->left == nullptr) {
            NodeSplay* temp = root;
            root = root->right;
            delete temp;
        }
        else {
            deleteLeftmostNodeRecursive(root->left);
        }
    }

    void deleteMultipleNodes(int n) {
        for (int i = 0; i < n; i++) {
            deleteLeftmostNode();
        }
    }

public:
    ~SplayTree() {
        deleteTree(root);
    }

private:
    void deleteTree(NodeSplay* root) {
        if (root == nullptr)
            return;

        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};
