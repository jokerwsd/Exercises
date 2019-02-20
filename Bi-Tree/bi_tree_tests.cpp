#include <bi_tree.h>
#include <iostream>
#include <vector>

using namespace std;

bool build_tree_from_array(BiTree<int>*& btree, vector<int>& data_stream) {
  if (data_stream.size() == 0) {
    cout << "Empty array!" << endl;
    return false;
  }
  for (auto data : data_stream) {
    btree->add_node(data);
  }
  return true;
}

int main(int argc, char** argv) {

  BiTree<int>* btree = new BiTree<int>();
  vector<int> a = {1, 2, 3, 4, 5};
  if (build_tree_from_array(btree, a)) {
    btree->print_tree(tree_order::POS_ORDER);
  }

  return 0;
}
