#ifndef _THREADED_BST
#define _THREADED_BST

struct Node {
  int data;
  Node* left;
  Node* right;
  bool rightThreaded;
};

class ThreadedBST {
  public:
    // Default constructor
    ThreadedBST();

    // Copy constructor
    ThreadedBST(const ThreadedBST& other);

    // Add a value to the tree
    void add(const int& x);

    // Remove a value from the tree
    bool remove(const int& x);

    // Check whether tree is empty
    bool isEmpty();

    // Check whether tree contains value
    bool contains(int& x);
    // bool subTreeContains(Node* node, int& x);

    // Get the vertical height of the tree
    int getHeight();

    // Get the number of nodes in the tree
    int getNumberOfNodes();

    // Get data of root node
    int getRootData();

    // Use threads to traverse nodes in-order and call func on each
    void inorderTraverse(int (*func)(int x));

    // In-order traverse and unlink and deallocate nodes
    void clear();

  private:
    int height;
    int numNodes;

    Node* root;
};

#endif // _THREADED_BST
