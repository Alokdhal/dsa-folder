//rest files will be updated in this repo....stay connected
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int par[N];

void dfs(int v, int p = -1)
{
    par[v] = p;
    for (int child : g[v])
    {
        if (child == p)
            continue;
        dfs(child, v);
    }
    return;
}
vector<int> path(int n)
{
    vector<int> ans;
    while (n != -1)
    {
        ans.push_back(n);
        n = par[n];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int v, e;
        cin >> v >> e;
        g[v].push_back(e);
        g[e].push_back(v);
    }
    dfs(1);
    int x, y;
    cin >> x >> y;
    vector<int> pathX = path(x);
    vector<int> pathY = path(y);

    int lca;
    for (int i = 0; i < n - 1; i++)
    {
        if (pathX[i] != pathY[i])
            break;
        lca = pathX[i];
    }
    cout << lca;
}