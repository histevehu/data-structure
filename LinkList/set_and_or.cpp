#include "iostream"
#include "LinkList.cpp"
using namespace std;

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

int main()
{
    LinkList<int> A, B, C, D;
    A.inputRear(-1);
    B.inputRear(-1);
    Union(A, B, C); //集合并运算
    C.output();
    Intersection(A, B, D); //集合交运算
    D.output();

    //   Union(A, B, C); //集合并运算

    //   Intersection(A, B, D); //集合交运算
    /*cout << A.getNum() << " " << B.getNum() << endl;
    int t;
    A.getData(1, t);
    cout << t << endl;
    B.getData(3, t);
    cout << t << endl;
    B.setData(1, t);
    B.output();
    A.insert(1, t);
    A.output();
    A.insert(4, t);
    A.output();
    cout << A.getNum() << " " << B.getNum();
    A.del(2, t);
    A.output();
    cout << A.getNum() << " " << B.getNum();
    B.clear();
    B.output();
    cout << A.getNum() << " " << B.getNum();
    C = A;
    C.output();
    cout << C.getNum();*/
    cin.get();
    cin.get();
    return 0;
}