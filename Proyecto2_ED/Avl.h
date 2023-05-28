#pragma once


#include <iostream>


struct NodeAvl {
    float value;
    NodeAvl* left;
    NodeAvl* right;
};

struct Avl {
    NodeAvl* root;
    std::string tipo = "AVL";
    bool listo = false;

    Avl() {
        root = NULL;;

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

    }

private:
    NodeAvl* createNode(float value) {
        NodeAvl* newNode = new NodeAvl;
        newNode->value = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    void insertNode(NodeAvl*& root, float value) {
        if (root == nullptr) {
            root = createNode(value);
            return;
        }

        if (value < root->value) {
            insertNode(root->left, value);
        }
        else if (value > root->value) {
            insertNode(root->right, value);
        }
    }

    int countNodesRecursive(NodeAvl* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + countNodesRecursive(root->left) + countNodesRecursive(root->right);
    }

    float getSumRecursive(NodeAvl* root) {
        if (root == nullptr) {
            return 0.0f;
        }

        return root->value + getSumRecursive(root->left) + getSumRecursive(root->right);
    }

    //Se carga el menor, para no ser tan mala nota :D
    void deleteLeftmostNodeRecursive(NodeAvl*& root) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr) {
            NodeAvl* temp = root;
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
    ~Avl() {
        deleteTree(root);
    }

private:
    void deleteTree(NodeAvl* root) {
        if (root == nullptr) {
            return;
        }

        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};