#include "iostream"
#include "Stack.cpp"
using namespace std;
int main()
{
    Stack<int> s1, s2(30);
    s1.print();
    s2.print();
    s1.push(2);
    s1.push(12);
    s2.push(36);
    s2.push(100);
    s1.print();
    s2.print();
    cout << s1.getSize() << " " << s2.getSize() << endl;
    s1.clear();
    s2.del();
    s1.print();
    s2.print();
    cout << s1.getSize() << " " << s2.getSize() << endl;
    int x;
    s2.pop(x);
    s1.print();
    s2.print();
    cout << x;
    cout << s1.getSize() << " " << s2.getSize() << endl;
    s2.clear();
    s1.print();
    s2.print();
    cout << s1.getSize() << " " << s2.getSize() << endl;
    cin.get();
}