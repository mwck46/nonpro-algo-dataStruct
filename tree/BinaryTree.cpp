#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stddef.h>
#include <vector>
#include <iostream>

template <typename T>
class TreeNode {
public:
  T val;
  bool isDeadBranch; // to differentiate NULL and 0 in c++
  TreeNode<T> *left;
  TreeNode<T> *right;
  TreeNode() : val(NULL), left(nullptr), right(nullptr), isDeadBranch(false) {}
  TreeNode(T x) : val(x), left(nullptr), right(nullptr), isDeadBranch(false) {}
  TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : val(x), left(left), right(right), isDeadBranch(false) {}

  template <typename T>
  friend class BinaryTree;
};

template <typename T>
class BinaryTree
{
private:

  // In: address of pointer
  // Out: address of pointer that points to the next TreeNode that is nullptr
  TreeNode<T>** _FindNextAvailableNodeAddress(TreeNode<T>** head)
  {
    // alias of the content of head of type (TreeNode<T>*)
    TreeNode<T>*& ptr = *head;

    if (ptr == nullptr)
      return &ptr;
    if (ptr->left == nullptr)
      return &ptr->left;
    if (ptr->right == nullptr)
      return &ptr->right;

    TreeNode<T>** rst;
    if (!ptr->left->isDeadBranch)
    {
      rst = _FindNextAvailableNodeAddress(&ptr->left);
      if (rst != NULL)
        return rst;
    }
    
    if (!ptr->right->isDeadBranch)
    {
      rst = _FindNextAvailableNodeAddress(&ptr->right);
      if (rst != NULL)
        return rst;
    }

    // both left and right child is dead branch indicates head is a leaf
    return NULL;
  }

  static void _PrintBreadthFirst(TreeNode<T>* head)
  {
    if (head == nullptr)
      return;
    if (head->left != nullptr)
    {
      if (!head->left->isDeadBranch)
        std::cout << "L=" << head->left->val << " ";
      else
        std::cout << "L=N" << " ";
    }
    if (head->right != nullptr)
    {
      if (!head->right->isDeadBranch)
        std::cout << "R=" << head->right->val << " ";
      else
        std::cout << "R=N" << " ";
    }
    _PrintBreadthFirst(head->left);
    _PrintBreadthFirst(head->right);
  }

public:
  TreeNode<T>* head;

  // Build Binary tree from vector and return the pointer to the 
  // head of the TreeNode<T>
  BinaryTree(const std::vector<T>& input)
  {
    TreeNode<T>* head = nullptr;

    for (T i : input)
    {
      TreeNode<T>** pNode = this->_FindNextAvailableNodeAddress(&head);
      *pNode = new TreeNode<T>;
      if (i == NULL)
        (*pNode)->isDeadBranch = true;
      else
        (*pNode)->val = i;
    }

    this->head = head;
  }

  // Print binary tree order according to depth first traversing
  static void PrintBinaryTreeDepthFirst(TreeNode<T>* head)
  {
    if (head == nullptr)
      return;

    if(!head->isDeadBranch)
      std::cout << head->val << " ";
    else
      std::cout << "N" << " ";
    BinaryTree::PrintBinaryTreeDepthFirst(head->left);
    BinaryTree::PrintBinaryTreeDepthFirst(head->right);
  }

  // Print binary tree order according to breadth first traversing
  static void PrintBinaryTreeBreadthFirst(TreeNode<T>* head)
  {
    if (head == nullptr)
      return;
    std::cout << head->val << " ";
    BinaryTree::_PrintBreadthFirst(head);
  }

  void PrintBreadthFirst()
  {
    BinaryTree::PrintBinaryTreeBreadthFirst(this->head);
  }
  
  void PrintDepthFirst()
  {
    BinaryTree::PrintBinaryTreeDepthFirst(this->head);
  }

};

#endif // !BINARYTREE_H

