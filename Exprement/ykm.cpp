#include <iostream>
#include <cctype>
using namespace std;
template <class T>
class SeqStack
{
private:
	T *elements;
	int maxSize;
	int top;

public:
	SeqStack(int sz) : top(-1), maxSize(sz) { elements = new T[maxSize]; }
	bool IsEmpty() { return top == -1; }
	void Push(T &x) { elements[++top] = x; }
	void Pop(T &x) { x = elements[top--]; }
	void getTop(T &x) { x = elements[top]; }
};
int isp(char ch)
{
	switch (ch)
	{
	case '#':
		return 0;
	case '(':
		return 1;
	case '*':
	case '/':
	case '%':
		return 5;
	case '+':
	case '-':
		return 3;
	case ')':
		return 6;
	}
}
int icp(char ch)
{
	switch (ch)
	{
	case '#':
		return 0;
	case '(':
		return 6;
	case '*':
	case '/':
	case '%':
		return 4;
	case '+':
	case '-':
		return 2;
	case ')':
		return 1;
	}
}
int main()
{
	SeqStack<char> s1(20);
	//SeqStack<char> s2;
	char ch = '#', ch1, op;
	s1.Push(ch);
	cin.get(ch);
	while (s1.IsEmpty() == false || ch != '#')
	{
		if (isdigit(ch))
		{
			cout << ch;
			cin.get(ch);
		}
		else
		{
			s1.getTop(ch1);
			if (isp(ch1) < icp(ch))
			{
				s1.Push(ch);
				cin.get(ch);
			}
			else if (isp(ch1) > icp(ch))
			{
				s1.Pop(op);

				cout << op;
			}
			else
			{
				s1.Pop(op);
				if (op == '(')
					cin.get(ch);
			}
		}
	}
	cin.get();
	cin.get();
}
