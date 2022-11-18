#include <iostream>
#include "Node.h"
#include "BinaryTree.h"
using namespace std;

/**
 * @brief Construct a new empty Binary Tree object
 */
BinaryTree::BinaryTree()
{
    root == nullptr;
}

/**
 * @brief Construct a new Binary Tree with two subtrees.
 * The subtrees become empty after this operation
 *
 * @param value The data at the root
 * @param lchild The left subtree
 * @param rchild The right subtree
 */
BinaryTree::BinaryTree(int value, BinaryTree &lchild, BinaryTree &rchild)
{
    root = new Node(value, lchild.root, rchild.root);
    lchild.root = nullptr;
    rchild.root = nullptr;
}

/**
 * @brief Indicate that this is the empty tree.
 *
 * @return true if tree is empty
 * @return false if tree is not empty
 */
bool BinaryTree::is_empty() const
{
    return root == nullptr;
}

/**
 * @brief Indicate that this tree is a leaf.
 *
 * @return true if tree is a leaf
 * @return false if tree is not a leaf
 */
bool BinaryTree::is_leaf() const
{
    return !is_empty() &&
           root->left == nullptr &&
           root->right == nullptr;
}

/**
 * @brief Indicate if the tree contains the given value
 *
 * @return true if the tree contains the given value
 * @return false if the tree does not contains the given value
 */
// retorna true se e somente se calue estiver na arvore
// enraizadas em node
bool contains_recursiva(Node *node, int value)
{ // caso de dase 1
    if (node == nullptr)
    {
        return false;
    }
    if (node->key == value)
    {
        return true;
    }
    else
    {
        return contains_recursiva(node->left, value) || contains_recursiva(node->right, volue);
    }
}

bool BinaryTree::contains(int value) const
{
    return contains_recursiva(root, value);
}
void print_keys_recursivo(Node, *node)
{
    if (node != nullptr)
    {
        cout << node->key << "";
        print_keys_recursivo(node->left);
        print_keys_recursivo(node->right);
    }
}

/**
 * @brief Print the keys saved on the tree
 */
void BinaryTree::print_keys() const
{
    print_keys_recursivo(root);
}
Node *clear_recursivo(Node, *node)
{
    if (node != nullptr)
    {
        node->left = clear_recursivo(node->left);
        node->right = clear_recursivo(node->right);
        delete node;
    }
    return nullptr;
}

/**
 * @brief empties the tree
 */
void BinaryTree::clear()
{
}

BinaryTree::~BinaryTree()
{
}