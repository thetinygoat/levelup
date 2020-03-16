#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void ngor(vector<int> a)
{
    queue<int> q1;
    for (int i = 0; i < a.size(); i++)
    {
        q1.push(a[i]);
    }
    int i = 0;
    while (!q1.empty())
    {
        int e = q1.front();
        q1.pop();
        bool flag = true;
        for (int j = i; j < a.size(); j++)
        {
            if (a[j] > e)
            {
                flag = false;
                cout << a[j] << " , ";
                break;
            }
        }
        if (flag)
            cout << -1 << " , ";
        i++;
    }
}

void ngol(vector<int> a)
{
    queue<int> q1;
    for (int i = 0; i < a.size(); i++)
    {
        q1.push(a[i]);
    }
    int i = 0;
    while (!q1.empty())
    {
        int e = q1.front();
        q1.pop();
        bool flag = true;
        for (int j = i; j >= 0; j--)
        {
            if (a[j] > e)
            {
                flag = false;
                cout << a[j] << " , ";
                break;
            }
        }
        if (flag)
            cout << -1 << " , ";
        i++;
    }
}
void nsor(vector<int> a)
{
    queue<int> q1;
    for (int i = 0; i < a.size(); i++)
    {
        q1.push(a[i]);
    }
    int i = 0;
    while (!q1.empty())
    {
        int e = q1.front();
        q1.pop();
        bool flag = true;
        for (int j = i; j < a.size(); j++)
        {
            if (a[j] < e)
            {
                flag = false;
                cout << a[j] << " , ";
                break;
            }
        }
        if (flag)
            cout << -1 << " , ";
        i++;
    }
}

int main()
{
    vector<int> a = {1, 3, 2, 4, 8, 6, 5, 9, 1};
    ngor(a);
    return 0;
}