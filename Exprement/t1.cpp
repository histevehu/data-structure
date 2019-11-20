#include <string>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

stack<double> cals;
double a, b;
char str[100];
int i = 0;

void cal(char c)
{
    if (isdigit(c) || c == '.')
    {
        str[i++] = c;
        str[i] = '\0';
    }
    if (c == ' ')
    {
        a = atof(str);
        cals.push(a);
        i = 0;
    }
    switch (c)
    {
    case '+':
        b = cals.top();
        cals.pop();
        a = cals.top();
        cals.pop();
        cals.push(a + b);
        break;
    case '-':
        b = cals.top();
        cals.pop();
        a = cals.top();
        cals.pop();
        cals.push(a - b);
        break;
    case '*':
        b = cals.top();
        cals.pop();
        a = cals.top();
        cals.pop();
        cals.push(a * b);
        break;
    case '/':
        b = cals.top();
        cals.pop();
        a = cals.top();
        cals.pop();
        if (b != 0)
            cals.push(a / b);
        break;
    }
    return;
}

int main()
{
    stack<char> s;
    char space = ' ';
    char c, e;
    cin.get(c);
    while (c != '\n')
    {
        if (c == '#')
            break;
        int flag = 0;
        while ((isdigit(c) || c == '.'))
        {
            cal(c);
            cin.get(c);
            if (c == '\n')
            {
                cal(space);
                flag = 1;
                break;
            }
            if (!isdigit(c) && c != '.')
            {
                cal(space);
            }
        }
        if (flag == 1)
            break;
        if (c == ')')
        {
            e = s.top();
            s.pop();
            while (e != '(')
            {

                cal(e);
                e = s.top();
                s.pop();
            }
        }
        else if (c == '+' || c == '-')
        {
            if (s.empty())
                s.push(c);
            else
            {
                do
                {
                    e = s.top();
                    s.pop();
                    if (e == '(')
                        s.push(e);
                    else
                    {
                        cal(e);
                    }
                } while (!s.empty() && e != '(');
                s.push(c);
            }
        }
        else if (c == '*' || c == '/' || c == '(')
            s.push(c);
        cin.get(c);
    }
    while (!s.empty())
    {
        e = s.top();
        s.pop();
        cal(e);
    }
    a = cals.top();
    cals.pop();
    cout << a << endl;
    cin.get();
    return 0;
}
