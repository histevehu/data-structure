#include <iostream>
using namespace std;
template <class T>
struct BinaryNode
{
    T data;
    BinaryNode *leftChild;
    BinaryNode *rightChild;
    BinaryNode(T x)
    {
        data = x;
        leftChild = NULL;
        rightChild = NULL;
    }
};
template <class T>
class BinaryTree
{
private:
    BinaryNode<T> *subTree;
    T RefValue;

public:
    BinaryTree(T value) { RefValue = value; }
    void CreateTree() { CreateTree(subTree); }
    void CreateTree(BinaryNode<T> *&root);
    int count() { count(subTree); }
    int count(BinaryNode<T> *&root);
    int count1() { count1(subTree); }
    int count1(BinaryNode<T> *&root);
    int count2() { count2(subTree); }
    int count2(BinaryNode<T> *&root);
};
template <class T>
void BinaryTree<T>::CreateTree(BinaryNode<T> *&root)
{
    T item;
    cin >> item;
    if (item != RefValue)
    {
        root = new BinaryNode<T>(item);
        CreateTree(root->leftChild);
        CreateTree(root->rightChild);
    }
    else
        root = NULL;
}
template <class T>
int BinaryTree<T>::count(BinaryNode<T> *&root)
{
    if (root->rightChild == NULL && root->leftChild == NULL)
        return 1;
    else if (root->leftChild == NULL)
    {
        return count(root->rightChild);
    }
    else if (root->rightChild == NULL)
    {
        return count(root->leftChild);
    }
    else
        return count(root->leftChild) + count(root->rightChild);
}
template <class T>
int BinaryTree<T>::count1(BinaryNode<T> *&root)
{
    if (root->rightChild == NULL && root->leftChild == NULL)
        return 0;
    else if (root->leftChild == NULL)
        return 1 + count1(root->rightChild);
    else if (root->rightChild == NULL)
        return 1 + count1(root->leftChild);
    else
        return count1(root->leftChild) + count1(root->rightChild);
}
template <class T>
int BinaryTree<T>::count2(BinaryNode<T> *&root)
{
    if (root->leftChild == NULL && root->rightChild == NULL)
        return 0;
    else if (root->leftChild == NULL)
        return count2(root->rightChild);
    else if (root->rightChild == NULL)
        return count2(root->leftChild);
    else
        return 1 + count2(root->leftChild) + count2(root->rightChild);
}
int main()
{
    BinaryTree<char> binary('#');
    binary.CreateTree();
    cout << binary.count() << " " << binary.count1() << " " << binary.count2() << " ";
    return 0;
}