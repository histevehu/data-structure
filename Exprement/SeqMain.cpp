#include "iostream"
using namespace std;

template <typename T>
class Seqlist
{
public:
    Seqlist(int s = 100)
    {
        size = s;
        last = -1;
        data = new T[size];
    }
    void input()
    {
        int n;
        while (1)
        {
            cin >> n;
            last = n - 1;
            if (last <= size - 1)
                break;
        }
        for (int i = 0; i <= last; i++)
            cin >> data[i];
    }
    void output()
    {
        cout << "{ ";
        for (int i = 0; i <= last; i++)
        {
            cout << data[i] << " ";
        }
        cout << "}" << endl;
    }
    void remove(int i, T &x)
    {
        x = data[i];
        for (int j = i; j < last; j++)
        {
            data[j] = data[j + 1];
        }
        last--;
        return;
    }
    T getData(int i)
    {
        return data[i];
    }

protected:
    T *data;
    int size;
    int last;
};

template <typename T>
bool search(Seqlist<T> &sl, int a, int b)
{
    T cmp;
lable:
    for (int i = 0; i <= sl.last; i++)
    {
        if (sl.getData(i) >= a && sl.getData(i) <= b)
        {
            sl.remove(i, cmp);
            goto lable;
        }
    }
    return true;
}

int main()
{
    Seqlist<int> s1;
    int a, b;
    s1.input();
    cin >> a >> b;
    if (a > b)
    {
        cout << "s or t error!";
        exit(-1);
    }
    search(s1, a, b);
    s1.output();
    cin.get();
    cin.get();
}