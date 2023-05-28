#pragma once
#include "Confi.h"


struct NodeBin {
    float value;
    NodeBin* left;
    NodeBin* right;
};

struct ArbolBinario {
    NodeBin* root;
    std::string tipo = "ARBOL BINARIO BUSQUEDA";
    bool listo = false;
    int x; int y;
    ArbolBinario() {
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
    NodeBin* createNode(float value) {
        NodeBin* newNode = new NodeBin;
        newNode->value = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    void insertNode(NodeBin*& root, float value) {
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

    int countNodesRecursive(NodeBin* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + countNodesRecursive(root->left) + countNodesRecursive(root->right);
    }

    float getSumRecursive(NodeBin* root) {
        if (root == nullptr) {
            return 0.0f;
        }

        return root->value + getSumRecursive(root->left) + getSumRecursive(root->right);
    }

    //Se carga el menor, para no ser tan mala nota :D
    void deleteLeftmostNodeRecursive(NodeBin*& root) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr) {
            NodeBin* temp = root;
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
    ~ArbolBinario() {
        deleteTree(root);
    }

private:
    void deleteTree(NodeBin* root) {
        if (root == nullptr) {
            return;
        }

        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}; 
