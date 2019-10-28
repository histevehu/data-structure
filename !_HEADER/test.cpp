#include "iostream"
#include "BinTree.cpp"
using namespace std;
int main()
{
    BinTree<char> b1('#');
    b1.create(b1.root);
    b1.treePicPrePrint();
    cin.get();
    cin.get();
}