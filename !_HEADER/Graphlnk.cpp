#include "iostream"
using namespace std;
template <typename T, typename E>
struct Edge
{
    int dest;
    E cost;
    Edge<T, E> *link;
    Edge() {}
    Edge(int num, E weight) : dest(num), cost(weight), link(NULL) {}
    bool operator!=(Edge<T, E> &R) const { return dest != R.dest ? true : false; }
};
template <typename T, typename E>
struct Vertex
{
    T data;
    Edge<T, E> *adj;
};

template <typename T, typename E>
class Graphlink
{
protected:
    int maxVertices;
    int numEdges;
    int numVertices;
    Vertex<T, E> *NodeTable;
    int getVertexPos(const T vt)
    {
        for (int i = 0; i < numVertices; i++)
        {
            if (NodeTable[i].data == vt)
                return i;
        }
        return -1;
    }

public:
    Graphlink(int sz)
    {
        maxVertices = sz;
        numVertices = 0;
        numEdges = 0;
        NodeTable = new Vertex<T, E>[maxVertices];
        if (NodeTable == NULL)
        {
            cerr << "RAM SPACE ALLOCATE FAILED!" << endl;
            exit(-1);
        }
        for (int i = 0; i < maxVertices; i++)
        {
            NodeTable[i].adj = NULL;
        }
    }
    ~Graphlink()
    {
        for (int i = 0; i < numVertices; i++)
        {
            Edge<T, E> *p = NodeTable[i].adj;
            while (p != NULL)
            {
                NodeTable[i].adj = p->link;
                delete p;
                p = NodeTable[i].adj;
            }
        }
        delete[] NodeTable;
    }
    int getNumEdges() { return numEdges; }
    int getNumVertices() { return numVertices; }
    T getValue(int i)
    {
        return (i >= o && i < numVertices) ? NodeTable[i].data : 0;
    }
    int getFirstNeighbor(int v)
    {
        if (v != -1)
        {
            Edge<T, E> *p = NodeTable[v].adj;
            if (p != NULL)
                return p->dest;
        }
        return -1;
    }
    int getNextNeighbor(int v, int w)
    {
        if (v != -1)
        {
            Edge<T, E> *p = NodeTable[v].adj;
            while (p != NULL && p->dest != w)
            {
                p = p->link;
            }
            if (p != NULL && p->link != NULL)
            {
                return p->link->dest;
            }
        }
        return -1;
    }
    E getWeight(int v1, int v2)
    {
        if (v1 != -1 && v2 != -1)
        {
            Edge<T, E> *p = NodeTable[v1].adj;
            while (p != NULL && p->dest != v2)
            {
                p = p->link;
            }
            if (p != NULL)
                return p->cost;
        }
        return 0;
    }
    bool insertVertex(const T &vertex)
    {
        if (numVertices == maxVertices)
            return false;
        NodeTable[numVertices].data = vertex;
        numVertices++;
        return true;
    }
    bool removeVertex(int v)
    {
        if (numVertices == 1 || v < 0 || v >= numVertices)
            return false;
        Edge<T, E> *p, *s, *t;
        int i, k;
        while (NodeTable[v].adj != NULL)
        {
            p = NodeTable[v].adj;
            k = p->dest;
            s = NodeTable[k].adj;
            t = NULL;
            while (s != NULL && s->dest != v)
            {
                t = s;
                s = s->link;
            }
            if (s != NULL)
            {
                if (t == NULL)
                    NodeTable[k].adj = s->link;
                else
                    t->link = s->link;
                delete s;
            }
            NodeTable[v].adj = p->link;
            delete p;
            numEdges--;
        }
        numVertices--;
        NodeTable[v].data = NodeTable[numVertices].data;
        p = NodeTable[v].adj = NodeTable[numVertices].adj;
        while (p != NULL)
        {
            s = NodeTable[p->dest].adj;
            while (s != NULL)
            {
                if (s->dest == numVertices)
                {
                    s->dest = v;
                    break;
                }
                else
                    s = s->link;
            }
        }
        return true;
    }
    bool insertEdge(int v1, int v2, E weight)
    {
        if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices)
        {
            Edge<T, E> *q, *p = NodeTable[v1].adj;
            while (p != NULL && p->dest != v2)
                p = p->link;
            if (p != NULL)
                return false;
            p = new Edge<T, E>;
            q = new Edge<T, E>;
            p->dest = v2;
            p->cost = weight;
            p->link = NodeTable[v1].adj;
            NodeTable[v1].adj = p;
            q->dest = v1;
            q->cost = weight;
            q->link = NodeTable[v2].adj = q;
            numEdges++;
            return true;
        }
        return 0;
    }
    bool removeEdge(int v1, int v2)
    {
        if (v1 != -1 && v2 != -1)
        {
            Edge<T, E> *p = NodeTable[v1].adj, *q = NULL, *s = p;
            while (p != NULL && p->dest != v2)
            {
                q = p;
                p = p->link;
            }
            if (p != NULL)
            {
                if (p == s)
                    NodeTable[v1].adj = p->link;
                else
                    q->link = p->link;
                delete p;
            }
            else
                return false;
            p = NodeTable[v2].adj;
            q = NULL, s = p;
            while (p->dest != v1)
            {
                q = p;
                p = p->link;
            }
            if (p == s)
                NodeTable[v2].adj = p->link;
            else
                q->link = p->link;
            delete p;
            return true;
        }
        return false;
    }
    void DFS(const T &v)
    {
        int i, loc, n = getNumVertices();
        bool *visited = new bool[n];
        for (i = 0; i < n; i++)
            visited[i] = false;
        loc = getVertexPos(v);
        DFS(loc, visited);
        delete[] visited;
    }
    void DFS(int v, bool visited[])
    {
        cout << getValue(v) << " ";
        visited[v] = true;
        int w = getFirstNeighbor(v);
        while (w != -1)
        {
            if (visited[w] == false)
                DFS(w, visited);
            w = getNextNeighbor(v, w);
        }
    }
};
