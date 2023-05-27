#pragma once


#include <iostream>
using namespace std;

struct Node {
    float value;
    Node* left;
    Node* right;
};

struct SplayTree {
    Node* root;
    string tipo = "ÁRBOL SPLAY";
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
    Node* createNode(float value) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    void splay(Node*& root, float value) {
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

    Node* rotateRight(Node* node) {
        Node* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;
        return newRoot;
    }

    Node* rotateLeft(Node* node) {
        Node* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;
        return newRoot;
    }

    void insertNode(Node*& root, float value) {
        if (root == nullptr) {
            root = createNode(value);
            return;
        }

        splay(root, value);

        if (value < root->value) {
            Node* newNode = createNode(value);
            newNode->left = root->left;
            newNode->right = root;
            root->left = nullptr;
            root = newNode;
        }
        else if (value > root->value) {
            Node* newNode = createNode(value);
            newNode->left = root;
            newNode->right = root->right;
            root->right = nullptr;
            root = newNode;
        }
    }

    int countNodesRecursive(Node* root) {
        if (root == nullptr)
            return 0;

        return 1 + countNodesRecursive(root->left) + countNodesRecursive(root->right);
    }

    float getSumRecursive(Node* root) {
        if (root == nullptr)
            return 0.0f;

        return root->value + getSumRecursive(root->left) + getSumRecursive(root->right);
    }

    void deleteLeftmostNodeRecursive(Node*& root) {
        if (root == nullptr)
            return;

        if (root->left == nullptr) {
            Node* temp = root;
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
    void deleteTree(Node* root) {
        if (root == nullptr)
            return;

        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};
