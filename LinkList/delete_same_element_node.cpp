#include "iostream"
using namespace std;

template <typename T>
struct LinkNode
{
    T data;
    LinkNode<T> *next;
    LinkNode(LinkNode<T> *p = NULL) { next = p; }
    LinkNode(const T &item, LinkNode<T> *p = NULL)
    {
        data = item;
        next = p;
    }
};

template <typename T>
class LinkList
{
public:
    LinkList()
    {
        head = new LinkNode<T>();
        num_node = 0;
    }
    LinkList(const T &item)
    {
        head = new LinkNode<T>(item);
        num_node = 0;
    }
    ~LinkList() { clear(); }
    LinkList(LinkList<T> &L)
    {
        T value;
        num_node = L.getNum();
        LinkNode<T> *ori = L.getHead();
        LinkNode<T> *tgt = (head = new LinkNode<T>);
        while (ori->next != NULL)
        {
            value = ori->next->data;
            tgt->next = new LinkNode<T>(value);
            tgt = tgt->next;
            ori = ori->next;
        }
    }
    LinkList<T> &operator=(LinkList<T> &L)
    {
        if (this != &L)
        {
            T value;
            num_node = L.getNum();
            LinkNode<T> *ori = L.getHead();
            LinkNode<T> *tgt = (head = new LinkNode<T>);
            while (ori->next != NULL)
            {
                value = ori->next->data;
                tgt->next = new LinkNode<T>(value);
                tgt = tgt->next;
                ori = ori->next;
            }
        }
        return *this;
    }
    int getNum() { return num_node; }
    void setNum(int x)
    {
        num_node = x;
    }
    void freshNum()
    {
        LinkNode<T> *cp = head->next;
        int count = 0;
        while (cp != NULL)
        {
            cp = cp->next;
            count++;
        }
        getNum = count;
    }
    LinkNode<T> *getHead() { return head; }
    LinkNode<T> *getLast()
    {
        LinkNode<T> *cp = head->next;
        if (cp == NULL)
            return NULL;
        while (cp != NULL)
        {
            if (cp->next == NULL)
                return cp;
            cp = cp->next;
        }
    }
    LinkNode<T> *search(T x)
    {
        LinkNode<T> *current = head->next;
        while (current != NULL)
        {
            if (current->data == x)
                break;
            else
                current = current->next;
        }
        return current;
    }
    LinkNode<T> *locate(int k)
    {
        if (k < 0 || k > num_node)
            return NULL;
        LinkNode<T> *current = head->next;
        int i = 0;
        while (i < k)
        {
            current = current->next;
            i++;
        }
        return current;
    }
    int locate_num(T &x)
    {
        LinkNode<T> *current = head->next;
        int i = 0;
        while (current != NULL)
        {
            if (current->data != x)
            {
                i++;
                current = current->next;
            }
            else
                return i;
        }
        return -1;
    }
    bool getData(int i, T &x)
    {
        if (i <= 0 || i > num_node)
            return false;
        LinkNode<T> *cp = locate(i);
        x = cp->data;
        return true;
    }
    bool setData(int i, T &x)
    {
        if (i <= 0 || i > num_node)
            return false;
        LinkNode<T> *cp = locate(i);
        cp->data = x;
        return true;
    }
    bool insert(int i, T &x)
    {
        LinkNode<T> *current = locate(i);
        if (current == NULL)
            return false;
        LinkNode<T> *newnode = new LinkNode<T>(x);
        if (newnode == NULL)
        {
            cerr << "Memory space apply failed.";
            exit(-1);
        }
        newnode->next = current->next;
        current->next = newnode;
        num_node++;
        return true;
    }
    bool del(int i, T &x)
    {
        if (i == 0)
        {
            LinkNode<T> *del = head->next;
            head->next = del->next;
            x = del->data;
            delete del;
            num_node--;
            return true;
        }
        else
        {
            LinkNode<T> *current = locate(i - 1);
            if (current == NULL || current->next == NULL)
                return false;
            LinkNode<T> *delnode = current->next;
            current->next = delnode->next;
            x = delnode->data;
            delete delnode;
            num_node--;
            return true;
        }
    }
    bool isEmpty() { return (head->next == NULL ? true : false); }
    void clear()
    {
        LinkNode<T> *cp;
        while (head->next != NULL)
        {
            cp = head->next;
            head->next = cp->next;
            delete cp;
        }
        num_node = 0;
    }
    void inputRear(T END_TAG)
    {
        LinkNode<T> *newnode, *last;
        T value;
        clear();
        cin >> value;
        last = head;
        while (value != END_TAG)
        {
            newnode = new LinkNode<T>(value);
            if (newnode == NULL)
            {
                cerr << "Memory space apply failed.";
                exit(-1);
            }
            last->next = newnode;
            last = newnode;
            num_node++;
            cin >> value;
        }
    }
    void output()
    {
        LinkNode<T> *p = head->next;
        if (p == NULL)
            cout << "空表!\n";
        else
        {
            while (p->next != NULL)
            {
                cout << p->data << "-->";
                p = p->next;
            }
            cout << p->data << endl;
        }
    }

private:
    int num_node;
    LinkNode<T> *head;
};

template <typename T>
void Union(LinkList<T> &A, LinkList<T> &B, LinkList<T> &C)
{
    LinkNode<T> *current = A.getHead()->next;
    if (current != NULL)
        C = A;
    current = B.getHead()->next;
    if (current != NULL)
    {
        while (current != NULL)
        {
            if (A.search(current->data) == NULL)
            {
                LinkNode<T> *newnode = new LinkNode<T>(current->data);
                if (newnode == NULL)
                {
                    cerr << "Memory space apply failed.";
                    exit(-1);
                }
                if (C.getLast() == NULL)
                    C.getHead()->next = newnode;
                else
                    C.getLast()->next = newnode;
                C.setNum(C.getNum() + 1);
            }
            current = current->next;
        }
    }
}
template <typename T>
void Intersection(LinkList<T> &A, LinkList<T> &B, LinkList<T> &C)
{
    Union(A, B, C);
    LinkNode<T> *current = C.getHead()->next;
    LinkNode<T> *del;
    T x;
    if (current != NULL)
    {
        while (current != NULL)
        {
            if (!((A.search(current->data) != NULL) && (B.search(current->data) != NULL)))
            {
                LinkNode<T> *cmp = current->next;
                C.del(C.locate_num(current->data), x);
                current = cmp;
                continue;
            }
            current = current->next;
        }
    }
}

template <typename T>
void tidyup(LinkList<T> &L)
{
    LinkNode<T> *p = L.getHead()->next;
    if (p == NULL)
        return;
    while (p != NULL)
    {
        if (p->data == p->next->data)
        {
            while (p->data == p->next->data)
            {
                LinkNode<T> *del = p->next;
                p->next = del->next;
                delete del;
                L.setNum(L.getNum() - 1);
                if (p->next == NULL)
                    return;
            }
        }
        p = p->next;
    }
}

int main()
{
    LinkList<int> A;
    A.inputRear(-1);
    A.output();
    tidyup(A);
    A.output();
    cin.get();
    cin.get();
    return 0;
}