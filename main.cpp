#include <algorithm>
#include <iostream>
#include <numeric>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "threadedbst.h"

using namespace std;

void test1() {
  cout << endl << "-- Fixed test 1 --" << endl;

  ThreadedBST bst;

  bst.add(8);
  bst.add(5);
  bst.add(10);
  bst.add(9);
  bst.add(11);
  bst.add(2);
  bst.add(6);

  cout << bst << endl;

  cout << "In-order traversal: ";
  bst.inorderTraverse();
}

void test2() {
  cout << endl << "-- Random insertion test 1 --" << endl;

  ThreadedBST bst;
  vector<int> v(10);

  iota(v.begin(), v.end(), 0); // fill with numbers from 0 to n
  random_shuffle(v.begin(), v.end()); // randomly shuffle

  cout << "Insertion order: ";
  for (int x : v) {
    cout << x << " ";
    bst.add(x);
  }
  cout << endl << endl;

  cout << bst << endl;
  cout << endl;

  cout << "In-order traversal: ";
  bst.inorderTraverse();
}

// Insert midpoint of vec into bst
void insertMidpoint(vector<int> vec, ThreadedBST &bst) {
  if (vec.size() == 0) {
    return;
  }

  int midIndex = int(vec.size() / 2);
  int val = vec[midIndex];

  cout << val << " ";
  bst.add(val);

  insertMidpoint(vector<int>(vec.begin(), vec.begin()+midIndex), bst);
  insertMidpoint(vector<int>(vec.begin()+midIndex+1, vec.end()), bst);
}

void testRequired(int n) {
  cout << endl << "-- Required assignment test --" << endl;

  ThreadedBST bst;

  vector<int> v(n);
  iota(v.begin(), v.end(), 0); // fill with numbers from 0 to n

  cout << "Insertion order: ";
  insertMidpoint(v, bst);
  cout << endl;

  cout << bst << endl;
  cout << endl;

  cout << "In-order traversal: ";
  bst.inorderTraverse();

  cout << endl << "Making copy..." << endl;
  ThreadedBST bstCopy(bst);

  cout << endl << "Deleting all even numbers..." << endl;
  cout << "ERROR: Not implemented" << endl; // TODO

  cout << endl << "In-order traversal: ";
  bst.inorderTraverse();
}

int main(int argc, char *argv[]) {
  srand(time(NULL));

  // TODO: take as CLI argument
  int n;
  if (argc > 1) {
    n = atoi(argv[1]);
  } else {
    n = 9;
  }

  test1();
  test2();
  testRequired(n);

  cout << "SUCCESSFUL EXECUTION!" << endl;

  return 0;
}
