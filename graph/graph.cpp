#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Edge
{
public:
    int v = 0;
    int w = 0;
    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};
int n = 7;
vector<vector<Edge *>> graph(n, vector<Edge *>());

void addEdge(int u, int v, int w)
{
    graph[u].push_back(new Edge(v, w));
    // graph[v].push_back(new Edge(u, w));
}

void removeVertex(int u)
{
    graph[u].clear();
}

// void removeEdge(int u, int v)
// {
//     for (auto i = graph[u].begin(); i < graph[u].end; i++)
//     {
//     }
// }

void display()
{
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (Edge *e : graph[i])
        {
            cout << "(" << e->v << ", " << e->w << ")";
        }
        cout << endl;
    }
}
int hamiltonianPath(int src, int dest, vector<bool> &vis, string ans, int pos)
{
    // cout << pos << endl;
    if (src == dest)
    {
        if (pos == n - 1)
            cout << ans + to_string(dest) << endl;
        return 1;
    }
    vis[src] = true;
    int count = 0;
    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
        {
            count += hamiltonianPath(e->v, dest, vis, ans + to_string(src) + " ", pos + 1);
        }
    }
    vis[src] = false;
    return count;
}

// dfs
int hamiltonianCycle(int src, int dest, vector<bool> &vis, string ans, int pos, int iv)
{
    // cout << pos << endl;
    if (src == dest)
    {
        if (pos == n - 1)
        {
            cout << ans + to_string(dest) << endl;
            for (Edge *e : graph[dest])
            {
                if (e->v == iv)
                {
                    cout << "hamiltonian cycle exists" << endl;
                }
            }
        }
        return 1;
    }
    vis[src] = true;
    int count = 0;
    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
        {
            count += hamiltonianCycle(e->v, dest, vis, ans + to_string(src) + " ", pos + 1, iv);
        }
    }
    vis[src] = false;
    return count;
}

void topologicalsort(vector<bool> &vis, stack<int> &st, int src)
{
    vis[src] = true;
    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
        {
            topologicalsort(vis, st, e->v);
        }
    }
    st.push(src);
}

void createGraph()
{
    addEdge(0, 1, 10);
    addEdge(0, 3, 10);
    addEdge(1, 2, 10);
    addEdge(2, 3, 40);
    addEdge(3, 4, 2);
    addEdge(4, 5, 2);
    addEdge(4, 6, 8);
    addEdge(5, 6, 3);
}

void solve()
{
    createGraph();
    // display();
    // cout << endl;
    // removeVertex(3);
    display();
    // removeEdge(0, 2);
    vector<bool> vis(n, false);
    // cout << hamiltonianPath(0, 6, vis, "", 0);
    // cout << hamiltonianCycle(0, 6, vis, "", 0, 0);
    stack<int> st;
    topologicalsort(vis, st, 5);
    int size = st.size();
    for (int i = 0; i < size; i++)
    {
        cout << st.top();
        st.pop();
    }
}

int main()
{
    solve();
    return 0;
}