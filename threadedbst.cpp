#include "threadedbst.h"

Node::Node(int data)
    : data(data), left(nullptr), right(nullptr), rthread(false) {}

Node *Node::leftMost() {
  Node *cur = this;
  while (cur->left != nullptr) {
    cur = cur->left;
  }
  return cur;
}

ThreadedBST::ThreadedBST() : numNodes(0), root(nullptr), threadHead(nullptr) {}

ThreadedBST::ThreadedBST(const ThreadedBST &other) { addSubTree(other->getRoot()); }

ThreadedBST::~ThreadedBST() {}

void printTree(ostream &out, const string prefix, const Node *node,
               bool isLeft) {
  if (node != nullptr) {
    cout << prefix;
    cout << (isLeft ? "├──" : "└──");
    cout << node->data << std::endl;

    // enter the next tree level - left and right branch
    printTree(out, prefix + (isLeft ? "│   " : "    "), node->left, true);
    if (!node->rthread) {
      printTree(out, prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
  }
}

void printTree(ostream &out, const Node *node) {
  printTree(out, "", node, false);
}

ostream &operator<<(ostream &out, const ThreadedBST &rhs) {
  if (rhs.isEmpty())
    out << "NULL" << endl;

  printTree(out, rhs.root);

  return out;
}

void ThreadedBST::add(const int &x) {
  Node *cur = root;
  while (cur != nullptr) {
    if (cur->data == x) {
      throw "Data already exists in tree.";
    }

    // -- Find insertion point
    if (x < cur->data) {
      // left subtree
      if (cur->left != nullptr) {
        cur = cur->left;
      } else {
        break;
      }
    } else {
      // right subtree
      if (cur->rthread == false) {
        cur = cur->right;
      } else {
        break;
      }
    }
  }
    
    

  // -- Insert
  Node *newNode = new Node(x);
  newNode->rthread = true; // new node will always be leaf so always have thread

  // keep threadHead always pointing to smallest node
  if (this->threadHead == nullptr || x < this->threadHead->data) {
    this->threadHead = newNode;
  }

  if (cur == nullptr) {
    // tree was empty, create root
    this->root = newNode;
  } else if (x < cur->data) {
    cur->left = newNode;
    newNode->right = cur;
  } else {
    newNode->right = cur->right;
    cur->right = newNode;
    cur->rthread = false;
  }

  this->numNodes++;
}

void ThreadedBST::addSubTree(const Node& toAdd){
    if(toAdd == nullptr){ return; } // cut method short if subtree head is empty
    add(toAdd->data);
    addSubTree(toAdd->left);
    addSubTree(toAdd->right);
}

bool ThreadedBST::remove(const int &x) { return false; }

bool ThreadedBST::isEmpty() const { return numNodes == 0; }

bool ThreadedBST::contains(const int &x) const {
  if (isEmpty())
    return false;

  Node *cur = root;
  while (cur != nullptr) {
    if (cur->data == x)
      return true;

    if (cur->data > x) {
      cur = cur->left;
    } else {
      cur = cur->right;
    }
  }

  return false;
}

int ThreadedBST::getHeight() const { return getHeightSubtree(root); }

int ThreadedBST::getHeightSubtree(const Node *node) const {
  if (node == nullptr)
    return 0;

  return max(getHeightSubtree(node->left), getHeightSubtree(node->right)) + 1;
}

int ThreadedBST::getNumberOfNodes() const { return numNodes; }

int ThreadedBST::getRootData() const {
  if (root != nullptr) {
    return root->data;
  }
  throw "Tree is empty. Can't fetch root data.";
}

Node* ThreadedBST::getRoot() const{
    if(root != nullptr){
      Node copy(root);
      return *copy;  
    }
    throw "Tree is empty. Can't fetch root.";   
}

void ThreadedBST::inorderTraverse() const {
  if (isEmpty()) {
    cout << "Tree is empty." << endl;
    return;
  }

  Node *cur = root->leftMost();
  while (cur != nullptr) {
    cout << cur->data << " ";

    if (cur->rthread) {
      cur = cur->right;
    } else {
      cur = cur->right->leftMost();
    }
  }

  cout << endl;
}

void ThreadedBST::clear() {
  // threaded in-order traversal
}
