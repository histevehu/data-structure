#include "iostream"
#include "Stack.cpp"
#include "string"
using namespace std;
int isp(char ch)
{
    switch (ch)
    {
    case '#':
        return 0;
        break;
    case '(':
        return 1;
        break;
    case '*':
    case '/':
    case '%':
        return 5;
        break;
    case '+':
    case '-':
        return 3;
        break;
    case ')':
        return 6;
        break;
    default:
        return -1;
    }
}
int icp(char ch)
{
    switch (ch)
    {
    case '#':
        return 0;
        break;
    case '(':
        return 6;
        break;
    case '*':
    case '/':
    case '%':
        return 4;
        break;
    case '+':
    case '-':
        return 2;
        break;
    case ')':
        return 1;
        break;
    default:
        return -1;
    }
}
int main()
{
    string data = "";
    Stack<char> cmp;
    char ch = '#', ch1, op;
    cmp.push(ch);
    cin.get(ch);
    while (!cmp.isEmpty() || ch != '#')
    {
        if (isdigit(ch))
        {

            data += ch;
            cin.get(ch);
        }
        else
        {
            cmp.getTop(ch1);
            if (isp(ch1) < icp(ch))
            {
                cmp.push(ch);
                cin.get(ch);
            }
            else if (isp(ch1) > icp(ch))
            {
                cmp.pop(op);

                data += op;
            }
            else
            {
                cmp.pop(op);
                if (op == '(')
                    cin.get(ch);
            }
        }
    }
    cout << data;
    cin.get();
    cin.get();
}
