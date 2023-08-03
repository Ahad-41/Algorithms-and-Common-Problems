#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N = 1e5 + 7;
vector<ll> adjList[N];
bool visited[N];

bool dfs(ll currNode, ll parent = -1) {
    visited[currNode] = true;

    bool isCycle = false;
    for (auto &u : adjList[currNode]) {
        if (visited[u] and u == parent) continue;
        if (visited[u]) return true;
        isCycle |= dfs(u, currNode);
    }

    return isCycle;
}

int main()
{
    ll node, edge; cin >> node >> edge;
    while (edge--) {
        ll u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool isCycle = false;
    for (ll i = 1; i <= node; i++) {
        if (visited[i]) continue;
        isCycle = dfs(i);
        if (isCycle) break;
    }

    cout << (isCycle ? "Cycle" : "Not Cycle") << endl;
}