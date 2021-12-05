#include "threadedbst.h"

void ThreadedBST::add(const int& x) {

}

bool ThreadedBST::remove(const int& x) {
  return false;
}

bool ThreadedBST::isEmpty() {
  return numNodes == 0;
}

bool ThreadedBST::contains(int& x) {
  if (isEmpty()) return false;

  Node* cur = root;
  while (cur != nullptr) {
    if (cur->data == x) return true;
    if (cur->data > x) {
      cur = cur->left;
    } else {
      cur = cur->right;
    }
  }

  // return subTreeContains(root, x);
  return false;
}

// bool ThreadedBST::subTreeContains(Node* node, int& x) {
//   if (node->data == x) {
//     return true;
//   } else if (node->left == nullptr && node->right == nullptr) {
//     return false;
//   } else {
//     if (node->left != nullptr) {
//       if (subTreeContains(node->left, x)) return true;
//       if (subTreeContains(node->right, x)) return true;
//       return false;
//     }
//   }
// }

int ThreadedBST::getHeight() {
  return height;
}

int ThreadedBST::getNumberOfNodes() {
  return numNodes;
}

int ThreadedBST::getRootData() {
  if (root != nullptr) {
    return root->data;
  } else {
    throw "Tree is empty. Can't fetch root data.";
  }
}

void ThreadedBST::inorderTraverse(int (*func)(int x)) {
  // threaded in-order traversal
  func(root->data);
}

void ThreadedBST::clear() {
  // threaded in-order traversal
}
