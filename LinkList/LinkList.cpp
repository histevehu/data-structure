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
    int getNum() { return num_node; }
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
        LinkNode<T> newnode = new LinkNode<T>(x);
        if (newnode == NULL)
        {
            cerr << "Memory space apply failed.";
            exit(-1);
        }
        newnode->next = current->next;
        current->next = newnode;
        return true;
    }
    bool del(int i, T &x)
    {
        LinkNode<T> *current = locate(i - 1);
        if (current == NULL || current->next == NULL)
            return false;
        LinkNode<T> *delnode = current->next;
        current->next = delnode->next;
        x = delnode->data;
        delete delnode;
        return true;
    }
    bool isEmpty { return (head->next == NULL ? true : false); }
    void claer()
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
    void input() {}
    void output(){
        LinkNode<T> *current = head->} LinkList(LinkList<T> &L)
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

private:
    int num_node;
    LinkNode<T> *head;
};
