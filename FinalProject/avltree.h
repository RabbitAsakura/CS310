//Jakobe McPhail
//11/27/25
#include <iostream>
typedef char ItemType;
#ifndef AVLTREE_H
#define AVLTREE_H

class TreeNode
{
    public:
        int value;
        TreeNode* left;
        TreeNode* right;
        TreeNode();
        TreeNode(int v);
};

class AVLTree
{
    public:
        TreeNode* root;
        AVLTree();
        bool isEmpty() const;
        int height(TreeNode* val);
        int balance(TreeNode* val);
        TreeNode* rotateRight(TreeNode* val);
        TreeNode* rotateLeft(TreeNode* val);
        TreeNode* insert(TreeNode* val, TreeNode* n);
        TreeNode* deleteNode(TreeNode* val, int n);
        TreeNode* minValue(TreeNode* val);
        void display(TreeNode* val, int space);
        void Preorder(TreeNode* r);
        void Inorder(TreeNode* r);
        void Postorder(TreeNode* r);
        TreeNode* Recursive(TreeNode* val, int n);
};
#endif