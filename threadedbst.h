#ifndef THREADED_BST_H
#define THREADED_BST_H

#include <iostream>
#include <functional>

using namespace std;

class Node {
  public:
    Node(int data);

    Node* leftMost();

    int data;
    Node* left;
    Node* right;
    bool rthread;
};

class ThreadedBST {
  friend ostream &operator<<(ostream &out, const ThreadedBST &rhs);

  public:
    // Default constructor
    ThreadedBST();

    // Copy constructor
    ThreadedBST(const ThreadedBST& other);

    // Destructor
    ~ThreadedBST();

    // Add a value to the tree
    void add(const int& x);

    // Remove a value from the tree
    bool remove(const int& x);

    // Check whether tree is empty
    bool isEmpty() const;

    // Check whether tree contains value
    bool contains(const int& x) const;

    // Get the vertical height of the tree
    int getHeight() const;
    int getHeightSubtree(const Node *node) const;

    // Get the number of nodes in the tree
    int getNumberOfNodes() const;

    // Get data of root node
    int getRootData() const;

    // Use threads to traverse nodes in-order and call func on each
    // void inorderTraverse(void (*func)(int x)) const;
    void inorderTraverse() const;

    // In-order traverse and unlink and deallocate nodes
    void clear();

  private:
    int numNodes;
    Node* root;
    Node* threadHead;
    void addSubTree(const Node& toAdd);
};

#endif // THREADED_BST_H
