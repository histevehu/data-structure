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
    Queue<T> operator=(Queue<T> &L)
    {
        first = NULL;
        last = NULL;
        QueueNode<T> *p = L.first;
        while (p != NULL)
        {
            enQueue(p->data);
            p = p->next;
        }
    }

protected:
    QueueNode<T> *first,
        *last;
};
int main()
{
    int m, n, k;
    Queue<int> q1, q2;
    cin >> m >> n;
    cin.get();
    cin >> k;
    cin.get();
    for (int i = 1; i <= m; i++)
    {
        q1.enQueue(i);
    }
    for (int i = 1; i <= n; i++)
    {
        q2.enQueue(i);
    }
    Queue<int> cq1 = q1, cq2 = q2;
    for (int i = 1; i <= k; i++)
    {
        int cmp1, cmp2;
        cq1.deQueue(cmp1);
        cq2.deQueue(cmp2);
        cout << cmp1 << " " << cmp2 << endl;
        if (cq1.isEmpty())
        {
            cq1 = q1;
        }
        if (cq2.isEmpty())
        {
            cq2 = q2;
        }
    }
    cin.get();
}