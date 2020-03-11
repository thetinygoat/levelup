#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <utility>

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
int n = 9;
vector<vector<Edge *>> graph(n, vector<Edge *>());

void addEdge(int u, int v, int w)
{
    graph[u].push_back(new Edge(v, w));
    graph[v].push_back(new Edge(u, w));
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

// bool bipartite(int src, vector<int> &vis)
// {
//     queue<pair<int, int>> q;
//     q.push({src, 0});
//     while (q.size() != 0)
//     {
//         pair<int, int> p = q.front();
//         q.pop();
//         // int e = p.first();
//         // int c = p.second();
//         vis[e] = c;
//         if (vis[e] != -1)
//         {
//             if (vis[e] != c)
//             {
//                 return false;
//             }
//             else
//             {
//                 continue;
//             }
//         }
//         for (Edge *el : graph[e])
//         {
//             if (vis[el->v] == -1)
//             {
//                 q.push({el->v, (c + 1) % 2});
//             }
//         }
//     }
//     return true;
// }

// void bipartitesol()
// {
//     for (int)
// }

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
    addEdge(2, 7, 40);
    addEdge(2, 8, 40);
    addEdge(3, 4, 2);
    addEdge(4, 5, 2);
    addEdge(4, 6, 8);
    addEdge(5, 6, 3);
    addEdge(8, 7, 40);
}
vector<int> low(n, 0);
vector<int> dis(n, 0);
vector<int> AP(n, 0);
vector<int> par(n, -1);
vector<bool> vis(n, false);
int countTime = 0;
int rootCount = 0;
void dfs(int src)
{
    vis[src] = true;
    dis[src] = low[src] = countTime++;
    for (Edge *e : graph[src])
    {
        if (!vis[e->v])
        {
            if (par[src] == -1)
                rootCount++;
            par[e->v] = src;
            dfs(e->v);
            if (dis[src] <= low[e->v])
                AP[src]++;
            if (dis[src] < low[e->v])
                cout << "AP EDGE " << src << " -> " << e->v << endl;
            low[src] = min(low[src], low[e->v]);
        }
        else if (par[src] != e->v)
        {
            low[src] = min(low[src], dis[e->v]);
        }
    }
}
void articulationPoint()
{
    vector<int> parent(n, 0);
    vector<bool> vis(n, false);
    vector<int> low;
    vector<int> dis;
    // for (vector<Edge *> v : graph)
    // {
    //     for (Edge *e : v)
    //     {
    //         if (!vis[e->v])
    //         {
    //             dfs(e->v);
    //         }
    //     }
    // }
    int src = 0;
    dfs(src);
    if (rootCount == 1)
        AP[src]--;

    for (int i = 0; i < AP.size(); i++)
    {
        cout << i << " " << AP[i] << endl;
    }
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
    // stack<int> st;
    // topologicalsort(vis, st, 5);
    // int size = st.size();
    // for (int i = 0; i < size; i++)
    // {
    //     cout << st.top();
    //     st.pop();
    // }
    articulationPoint();
}

int main()
{
    solve();
    return 0;
}