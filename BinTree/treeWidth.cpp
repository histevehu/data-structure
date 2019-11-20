#include "iostream"
using namespace std;

template <typename T>
struct QueueNode
{
    T data;
    QueueNode *next;
    QueueNode(QueueNode<T> *p = NULL) { next = p; }
    QueueNode(const T &item, QueueNode<T> *p = NULL)
    {
        data = item;
        next = p;
    }
};
template <typename T>
class Queue
{
public:
    Queue()
    {
        first = NULL;
        last = NULL;
    }
    bool enQueue(const T &x)
    {
        if (first == NULL)
        {
            first = last = new QueueNode<T>(x);
            if (first == NULL)
                return false;
        }
        else
        {
            last->next = new QueueNode<T>(x);
            if (last->next == NULL)
                return false;
            last = last->next;
        }
        return true;
    }
    bool deQueue(T &x)
    {
        if (isEmpty())
            return false;
        QueueNode<T> *p = first;
        x = p->data;
        first = first->next;
        return true;
    }
    bool getFirst(T &x)
    {
        if (isEmpty())
            return false;
        x = first->data;
        return true;
    }
    int getSize()
    {
        QueueNode<T> *p = first;
        int k = 0;
        while (p != NULL)
        {
            p = p->next;
            k++;
        }
        return k;
    }
    bool isEmpty()
    {
        return (first == NULL ? true : false);
    }
    void clear()
    {
        QueueNode<T> *p;
        while (first != NULL)
        {
            p = first;
            first = first->next;
            delete p;
        }
    }
    void print()
    {
        QueueNode<T> *p = first;
        int k = 0;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
            k++;
        }
        cout << endl;
    }

protected:
    QueueNode<T> *first, *last;
};

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

    void create() { create(root); }
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

    int height() { height(root); }
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

    void levelOrder()
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
    bool isFullBinTree()
    {
        isFullFlag = true;
        treeHeight = height();
        bottomBlank = false;
        isFullBinTree(root);
    }
    bool isFullBinTree(BinTreeNode<T> *node)
    {
        if (node != NULL)
        {
            if (height(node) != 2)
            {
                if ((node->left == NULL && node->right == NULL) || isFullBinTree(node->left) && isFullBinTree(node->right))
                {
                    isFullFlag = true;
                    return true;
                }
                if (node->left == NULL || node->right == NULL)
                {
                    isFullFlag = false;
                    return false;
                }
            }
            else
            {
                if ((node->right != NULL && node->left == NULL) || bottomBlank == true)
                {
                    isFullFlag = false;
                    return false;
                }
                else
                {
                    if (node->right == NULL && node->left != NULL)
                        bottomBlank = true;
                    isFullFlag = true;
                    return true;
                }
            }
            if (node == root)
            {
                if (isFullFlag)
                    return true;
                else
                    return false;
            }
        }
        else
        {
            return false;
        }
    }

    void find(T item)
    {
        findPointer = NULL;
        CMProot = root;
        isFind = false;
        find(root, item);
    }
    BinTreeNode<T> *find(BinTreeNode<T> *root, T item)
    {
        if (root != NULL)
        {
            if (item == root->data)
            {
                isFind = true;
                findPointer = root;
                return root;
            }
            else
            {
                BinTreeNode<T> *cmp = NULL;
                cmp = find(root->left, item);
                if (cmp != NULL)
                {
                    //                   findPointer = root->left;
                    isFind = true;
                    return cmp;
                }
                cmp = find(root->right, item);
                if (cmp != NULL)
                {
                    //                   findPointer = root->right;
                    isFind = true;
                    return cmp;
                }

                return NULL;
            }
        }
        else
        {
            return NULL;
        }
    }
    BinTreeNode<T> *findPointer;
    BinTreeNode<T> *CMProot;
    void levelNum(BinTreeNode<T> *root, int *a)
    {
        for (int i = 0; i <= height(root) + 1; i++)
        {
            a[i] = 0;
        }
        if (root != NULL)
            a[0] = 1;
        else
            return;
        Queue<BinTreeNode<T> *> Q;
        Queue<int> level;
        int q_level = 0;
        BinTreeNode<T> *p = root;
        Q.enQueue(p);
        level.enQueue(0);
        while (!Q.isEmpty())
        {

            Q.deQueue(p);
            level.deQueue(q_level);
            //          visit(p);
            if (p->left != NULL)
            {

                a[q_level + 1]++;
                /*
                cout << p->left->data << " ";
                for (int i = 0; i < height(); i++)
                {
                    cout << a[i] << " ";
                }
                cout << endl;*/
                Q.enQueue(p->left);
                level.enQueue(q_level + 1);
            }
            if (p->right != NULL)
            {
                a[q_level + 1]++;
                /*cout << p->right->data << " ";
                for (int i = 0; i < height(); i++)
                {
                    cout << a[i] << " ";
                }
                cout << endl;*/
                Q.enQueue(p->right);
                level.enQueue(q_level + 1);
            }
        }
    }
    template <typename C>
    C getArrMax(C *a, int len)
    {
        C max = a[0];
        for (int i = 0; i < len; i++)
        {
            if (a[i] > max)
                max = a[i];
        }
        return max;
    }

protected:
    T inEOF;
    bool isFullFlag;
    int treeHeight;
    bool bottomBlank;
    bool isFind;
    BinTreeNode<T> *root;
    BinTreeNode<T> *parent(BinTreeNode<T> *subTree, BinTreeNode<T> *tgt)
    {
        if (subTree == NULL)
            return NULL;
        if (subTree->left == tgt || subTree->right == tgt)
            return subTree;
        BinTreeNode<T> *p;
        if ((p = parent(subTree->left, tgt)) != NULL)
            return p;
        else
            return parent(subTree->right, tgt);
    }
};

int main()
{
    BinTree<char> b1('#');
    b1.create();
    cin.get();
    int levelNum[b1.height()];
    /*   cout << b1.height() << endl;
	cout << b1.height(b1.getRoot()->left) << endl;
	cout << b1.height(b1.getRoot()->left->left) << endl;
	cout << b1.height(b1.getRoot()->left->right) << endl;
	cout << b1.height(b1.getRoot()->left->right->left) << endl;
	cout << b1.height(b1.getRoot()->left->right->right) << endl;
	cout << b1.height(b1.getRoot()->left->right->left->right) << endl;*/
    b1.levelNum(b1.getRoot(), levelNum);
    /*for (int i = 0; i < b1.height(); i++)
    {
        cout << levelNum[i] << " ";
    }
    cout << endl;*/
    cout << b1.getArrMax(levelNum, b1.height());
    cin.get();
    cin.get();
}