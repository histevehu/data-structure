#include "iostream"
#include "Queue.cpp"
using namespace std;
int main()
{
    Queue<int> s1;
    int x;
    s1.print();
    s1.enQueue(2);
    s1.enQueue(12);
    s1.enQueue(30);
    s1.enQueue(34);
    s1.enQueue(36);
    s1.print();
    s1.getFirst(x);
    cout << x << endl;
    cout << s1.getSize() << endl;
    s1.deQueue(x);
    cout << x << endl;
    s1.clear();
    s1.print();
    cout << s1.getSize() << endl;
    cin.get();
}