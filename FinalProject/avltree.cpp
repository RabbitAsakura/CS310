//Jakobe McPhail
//Sean McElwee
//11/27/25
#include <iostream>
#include "avltree.h"
using namespace std;

/*struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;
};*/

TreeNode::TreeNode()
        {
            value = 0;
            right = NULL;
            left = NULL;
        }
        TreeNode::TreeNode(int v)
        {
            value = v;
            right = NULL;
            left = NULL;
        }

  AVLTree::AVLTree()
        {
            root = NULL;
        }

bool AVLTree::isEmpty() const
{
    return root == NULL;
}

int AVLTree::height(TreeNode* val)
{
    if(val == NULL)
    {
        return -1;
    }
    else
    {
        int lheight = height(val->left);
        int rheight = height(val->right);
        if(lheight > rheight)
        {
            return lheight + 1;
        }
        else
        {
            return rheight + 1;
        }
    }
}

int AVLTree::balance(TreeNode* val)
{
    if(val == NULL)
    {
        return 0;
    }
    return height(val->left) - height(val->right);
}


TreeNode* AVLTree::rotateRight(TreeNode* val)
{
    TreeNode* x = val->left;
    TreeNode* y = x->right;
    x->right = val;
    val->left = y;
    return x;
}

TreeNode* AVLTree::rotateLeft(TreeNode* val)
{
    TreeNode* y = val->right;
    TreeNode* x = y->left;
    y->left = val;
    val->right = x;
    return y;
}

TreeNode* AVLTree::insert(TreeNode* val, TreeNode* item)
{
    if(val == NULL)
    {
        //val = item;
        std::cout << "New Value Inserted" << std::endl;
        return item;
    }
    
    if(item->value < val->value)
    {
        val->left = insert(val->left, item);
    }
    else if(item->value > val->value)
    {
        val->right = insert(val->right, item);
    }
    else
    {
        std::cout << "No Duplicates!" << std::endl;
        return val;
    }

    int getBalance = balance(val);
    if (getBalance > 1 && item->value < val->left->value)
    {
        return rotateRight(val);
    }

    if (getBalance < -1 && item->value > val->right->value)
    {
        return rotateLeft(val);
    }
    if(getBalance > 1 && item->value < val->left->value)
    {
        val->left = rotateLeft(val->left);
        return rotateRight(val);
    }

    if(getBalance < -1 && item->value > val->right->value)
    {
        val->right = rotateRight(val->right);
        return rotateLeft(val);
    }

    return val;
}

TreeNode* AVLTree::deleteNode(TreeNode* val, int n)
{
    if(val == NULL)
    {
        return NULL;
    }
    else if(n < val->value)
    {
        val->left = deleteNode(val->left, n);
    }
    else if(n > val->value)
    {
        val->right = deleteNode(val->right, n);
    }
    else
    {
        
        if(val->left == NULL)
        {
            TreeNode* temp = val->right;
            delete val;
            return temp;
        }
        else if(val->right == NULL)
        {
            TreeNode* temp = val->left;
            delete val;
            return temp;
        }
        else
        {
            TreeNode* temp = minValue(val->right);
            val->value = temp->value;
            val->right = deleteNode(val->right, temp->value);
        }
    }
    return val;
}

TreeNode* AVLTree::minValue(TreeNode* val)
{
    TreeNode* current = val;
    while(current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

void AVLTree::Preorder(TreeNode* r)
{
    if(r == NULL)
    {
        return;
    }
    std::cout << r->value << " ";
    Preorder(r->left);
    Preorder(r->right);
}

void AVLTree::Inorder(TreeNode* r)
{
    if(r == NULL)
    {
        return;
    }
    Inorder(r->left);
    std::cout << r->value << " ";
    Inorder(r->right);
}

void AVLTree::Postorder(TreeNode* r)
{
    if(r == NULL)
    {
        return;
    }
    Postorder(r->left);
    Postorder(r->right);
    std::cout << r->value << " ";
}


void AVLTree::display(TreeNode* val, int space)
{
    if(val == NULL)
    {
        return;
    }
    space += space;
    display(val->right, space);
    std::cout << std::endl;
    
    for(int i = 0; i < space; i++)
    {
        std::cout << " ";
    }
    std::cout << val->value << "\n";
    display(val->left, space);
}

TreeNode* AVLTree::Recursive(TreeNode *n, int val)
{
    if(n == NULL || n->value == val)
    {
        return n;
    }
    else if(val < n->value)
    {
        return Recursive(n->left, val);
    }
    else
    {
        return Recursive(n->right, val);
    }
}