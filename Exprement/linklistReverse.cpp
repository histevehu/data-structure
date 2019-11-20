#include "iostream"

using namespace std;

template <typename T>
struct Stack_Node
{
    T data;
    Stack_Node *next;
    Stack_Node(Stack_Node<T> *p = NULL) { next = p; }
    Stack_Node(const T &item, Stack_Node<T> *p = NULL)
    {
        data = item;
        next = p;
    }
};

template <typename T>
class Stack
{
public:
    Stack() { top = NULL; }
    Stack(T din) { top = new Stack_Node<T>(din); }
    ~Stack() { clear(); }
    bool push(const T &x)
    {
        Stack_Node<T> *item = new Stack_Node<T>(x);
        if (item == NULL)
            return false;
        if (top == NULL)
            top = item;
        else
        {
            item->next = top;
            top = item;
        }
        return true;
    }
    bool pop(T &x)
    {
        if (isEmpty())
            return false;
        Stack_Node<T> *p = top;
        top = top->next;
        x = p->data;
        delete p;
        return true;
    }

    bool getTop(T &x)
    {
        if (isEmpty())
            return false;
        Stack_Node<T> *p = top;
        x = p->data;
    }

    bool del()
    {
        if (isEmpty())
            return false;
        Stack_Node<T> *p = top;
        top = top->next;
        delete p;
        return true;
    }
    bool isEmpty() { return (top == NULL); }
    int getSize()
    {
        if (isEmpty())
            return 0;
        Stack_Node<T> *p = top;
        int count = 0;
        while (p != NULL)
        {
            count++;
            p = p->next;
        }
        return count;
    }
    bool clear()
    {
        if (isEmpty())
            return true;
        Stack_Node<T> *p;
        while (top != NULL)
        {
            p = top;
            top = top->next;
            delete p;
        }
        return true;
    }
    void print()
    {
        Stack_Node<T> *p = top;
        cout << "[";
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << "]" << endl;
    }

private:
    Stack_Node<T> *top;
};

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
    LinkList<T> operator=(LinkList<T> L)
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
            return head;
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
        if (i < 0 || i > num_node - 1)
            return false;
        if (i == 0)
        {
            if (head->next != NULL)
            {
                x = head->next->data;
                return true;
            }
            else
            {
                return false;
            }
        }
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
    void inputRear(T END_TAG, T data)
    {
        LinkNode<T> *node = new LinkNode<T>(data);
        getLast()->next = node;
    }
    void output()
    {
        LinkNode<T> *current = head->next;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

private:
    int num_node;
    LinkNode<T> *head;
};

using namespace std;
int main()
{
    LinkList<int> l1;
    Stack<int> s1;
    l1.inputRear(-1);
    l1.output();
    int cmp, k = 0;
    while (l1.getData(k++, cmp) && k <= l1.getNum())
    {
        s1.push(cmp);
    }
    l1.clear();
    k = 1;
    while (s1.isEmpty() == false)
    {
        s1.pop(cmp);
        l1.inputRear(-1, cmp);
    }
    l1.output();
    cin.get();
    cin.get();
}