#include "iostream"
#include "BinTree.cpp"
#include "string"
using namespace std;

int main()
{
    BinTree<char> b1('#');
    b1.create();
    cin.get();
    BinTreeNode<char> *nd = b1.parent(b1.getRoot()->left->left);
    cin.get();
    cin.get();
}
