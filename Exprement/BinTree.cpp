#include "iostream"
#include "Queue.cpp"
using namespace std;

template <typename T>
struct BinTreeNode
{
    T data;
    BinTreeNode<T> *left, *right;
    BinTreeNode(T x, BinTreeNode<T> *L = NULL, BinTreeNode<T> *R = NULL) : data(x), left(L), right(R) {}
};
template <typename T>
class BinTree
{
public:
    BinTree() : root(NULL) {}
    BinTree(T value) : inEOF(value), root(NULL) {}
    BinTree(const BinTree<T> &s)
    {
        root = copy(s.root);
    }

    void destroy(BinTreeNode<T> *subTree)
    {
        if (subTree != NULL)
        {
            destroy(subTree->left);
            destroy(subTree->right);
            delete subTree;
        }
    }
    ~BinTree() { destroy(root); }

    void create(BinTreeNode<T> *&subTree)
    {
        T item;
        if (!cin.eof())
        {
            cin >> item;
            if (item != inEOF)
            {
                subTree = new BinTreeNode<T>(item);
                if (subTree == NULL)
                {
                    cerr << "Space Allocation ERROR!" << endl;
                    exit(-1);
                }
                create(subTree->left);
                create(subTree->right);
            }
            else
                subTree = NULL;
        }
    }

    void createFullBinTree(BinTreeNode<T> *&subTree, char data[], int pos, int upper)
    {
        if (data[pos] == '#' || pos > upper - 1)
            subTree = NULL;
        else
        {
            subTree = new BinTreeNode<T>(data[pos]);
            createFullBinTree(subTree->left, data, 2 * pos, upper);
            createFullBinTree(subTree->right, data, 2 * pos + 1, upper);
        }
    }

    bool isEmpty()
    {
        return (root == NULL) ? true : false;
    }

    int size(BinTreeNode<T> *subTree)
    {
        if (subTree == NULL)
            return 0;
        else
            return 1 + size(subTree->left) + size(subTree->right);
    }

    int height(BinTreeNode<T> *subTree)
    {
        if (subTree == NULL)
            return 0;
        else
        {
            int i = height(subTree->left);
            int j = height(subTree->right);
            return (i < j) ? j + 1 : i + 1;
        }
    }

    void prePrint(BinTreeNode<T> *subTree)
    {
        if (subTree != NULL)
        {
            cout << subTree->data << " ";
            if (subTree->left != NULL || subTree->right != NULL)
            {
                cout << '(';
                prePrint(subTree->left);
                cout << ',';
                if (subTree->right != NULL)
                    prePrint(subTree->right);
                cout << ')';
            }
        }
    }

    void treePicPrePrint()
    {
        treePicPrePrint(1, root);
    }
    void treePicPrePrint(int i, BinTreeNode<T> *subTree)
    {
        if (subTree != NULL)
        {
            for (int j = 1; j <= i; j++)
                cout << "-";
            visit(subTree);
            cout << endl;
            int k = ++i;
            treePicPrePrint(k, subTree->left);
            treePicPrePrint(k, subTree->right);
        }
    }

    BinTreeNode<T> *getRoot()
    {
        return root;
    }

    BinTreeNode<T> *parent(BinTreeNode<T> *cur)
    {
        parent(root, cur);
    }

    BinTreeNode<T> *left(BinTreeNode<T> *cur)
    {
        return (cur != NULL) ? cur->left : NULL;
    }

    BinTreeNode<T> *right(BinTreeNode<T> *cur)
    {
        return (cur != NULL) ? cur->right : NULL;
    }

    BinTreeNode<T> *copy(BinTreeNode<T> *subTree)
    {
        if (subTree == NULL)
            return NULL;
        BinTreeNode<T> *tmp_root = new BinTreeNode<T>;
        tmp_root->data = subTree->data;
        tmp_root->left = copy(subTree->left);
        tmp_root->right = copy(subTree->right);
        return tmp_root;
    }

    void visit(BinTreeNode<T> *node)
    {
        if (node != NULL)
        {
            cout << node->data << " ";
        }
    }

    BinTreeNode<T> *find(BinTreeNode<T> *root, T item)
    {
        CMProot = root;
        isFind = false;
        if (root != NULL)
        {
            if (item == root->data)
            {
                printf("success\n");
                isFind = true;
                return root;
            }
            else
            {
                BinTreeNode<T> *cmp = NULL;
                cmp = find(root->left, item);
                if (cmp != NULL)
                {
                    if (root == CMProot)
                        printf("success\n");
                    isFind = true;
                    return cmp;
                }
                cmp = find(root->right, item);
                if (cmp != NULL)
                {
                    if (root == CMProot)
                        printf("success\n");
                    isFind = true;
                    return cmp;
                }
                if (root == getRoot() && isFind == false)
                {
                    printf("failure\n");
                }
                return NULL;
            }
        }
        else
        {
            return NULL;
        }
    }

    void preOrder(BinTreeNode<T> *subTree)
    {
        if (subTree != NULL)
        {
            visit(subTree);
            preOrder(subTree->left);
            preOrder(subTree->right);
        }
    }
    void midOrder(BinTreeNode<T> *subTree)
    {
        if (subTree != NULL)
        {
            midOrder(subTree->left);
            visit(subTree);
            midOrder(subTree->right);
        }
    }
    void postOrder(BinTreeNode<T> *subTree)
    {
        if (subTree != NULL)
        {
            postOrder(subTree->left);
            postOrder(subTree->right);
            visit(subTree);
        }
    }

    void levelOrder(BinTreeNode<T> *subTree)
    {
        Queue<BinTreeNode<T> *> Q;
        BinTreeNode<T> *p = root;
        Q.enQueue(p);
        while (!Q.isEmpty())
        {

            Q.deQueue(p);
            visit(p);
            if (p->left != NULL)
                Q.enQueue(p->left);
            if (p->right != NULL)
                Q.enQueue(p->right);
        }
    }

    bool operator==(BinTree<T> &t)
    {
        return (equal(root, t.getRoot()) ? true : false);
    }

    bool equal(BinTreeNode<T> *n1, BinTreeNode<T> *n2)
    {
        if (n1 == NULL && n2 == NULL)
            return true;
        if ((n1 != NULL) && (n2 != NULL) && (n1->data == n2->data) && (equal(n1->left, n2->left)) && (equal(n1->right, n2->right)))
            return true;
        else
            return false;
    }
    BinTreeNode<T> *root;
    BinTreeNode<T> *CMProot;

protected:
    T inEOF;
    bool isFind;

    BinTreeNode<T> *parent(BinTreeNode<T> *subTree, BinTreeNode<T> *tgt)
    {
        if (subTree == NULL)
            return NULL;
        if (subTree->left == tgt || subTree->right == tgt)
            return subTree;
        BinTreeNode<T> *p;
        if (p == parent(subTree->left, tgt) != NULL)
            return p;
        else
            return parent(subTree->right, tgt);
    }
};
