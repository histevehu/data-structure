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