#include "math.h"
#include "Stack.cpp"
#include "iostream"
using namespace std;
class calc
{
public:
    calc(int sz) : s(sz) {}
    void run_postEqu()
    {
        char ch;
        double newOperand;
        cin >> ch;
        while (ch != '#')
        {
            switch (ch)
            {
            case '+':
            case '-':
            case '*':
            case '/':
                doOperator(ch);
                break;
            default:
                cin.putback(ch);
                cin >> newOperand;
                cin.get();
            }
            cin >> ch;
        }
    }
    void run_midEqu()
    {
    }
    void clear() { s.clear(); }

private:
    Stack<double> s;
    void addOprand(double value)
    {
        s.push(value);
    }
    bool get2Operands(double &left, double &right)
    {
        if (s.isEmpty())
        {
            cerr << "Right Operand Lack!" << endl;
            return false;
        }
        s.pop(right);
        if (s.isEmpty())
        {
            cerr << "Left Operand Lack!" << endl;
            return false;
        }
        s.pop(left);
        return true;
    }
    void doOperator(char op)
    {
        double left, right, value;
        if (get2Operands(left, right))
        {
            switch (op)
            {
            case '+':
                value = left + right;
                s.push(value);
                break;
            case '-':
                value = left - right;
                s.push(value);
                break;
            case '*':
                value = left * right;
                s.push(value);
                break;
            case '/':
                if (right == 0.0)
                {
                    cerr << "Divided by 0!" << endl;
                    clear();
                }
                else
                {
                    value = left / right;
                    s.push(value);
                    break;
                }
            }
            cout << value << endl;
        }
        else
        {
            clear();
        }
    };
};
int main()
{
    calc c1(0);
    c1.run_postEqu();
    cin.get();
    cin.get();
}