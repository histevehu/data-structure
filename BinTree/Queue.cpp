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