#include "iostream"
using namespace std;

template <typename T>
class Seqlist
{
public:
    Seqlist()
    {
        size = 100;
        last = -1;
        data = new T[size];
    }
    Seqlist(int s)
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
            data[j] = data[j+1];
        }
        last--;
        return;
    }
    void search(int a, int b)
    {
        T cmp;
        for (int i = 0; i <= last; i++)
        {
            if (data[i] >= a && data[i] <= b)
            {
                remove(i, cmp);
            }
        }
    }

protected:
    T *data;
    int size;
    int last;
};