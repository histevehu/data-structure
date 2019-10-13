#include "iostream"
#include "Stack.cpp"
using namespace std;
int main()
{
    int num;
    Stack<int> s1;
    cin >> num;
    cin.get();
    while (num > 1)
    {
        s1.push(num % 2);
        num /= 2;
    }
    s1.push(1);
    s1.print();
    cin.get();
}