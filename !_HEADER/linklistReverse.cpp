#include "iostream"
#include "LinkList.cpp"
#include "Stack.cpp"

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