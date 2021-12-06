#include <algorithm>
#include <iostream>
#include <numeric>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "threadedbst.h"

using namespace std;

int main() {
  srand(time(NULL));

  // TODO: take as CLI argument
  const int n = 9;
  vector<int> v(n);

  ThreadedBST bst;
  cout << bst << endl;

  // iota(v.begin(), v.end(), 0); // fill with numbers from 0 to n
  // random_shuffle(v.begin(), v.end()); // randomly shuffle

  v.clear();
  v.push_back(8);
  v.push_back(5);
  v.push_back(10);
  v.push_back(9);
  v.push_back(11);
  v.push_back(2);
  v.push_back(6);

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

  cout << "SUCCESSFUL EXECUTION!" << endl;

  return 0;
}
