#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll N = 1e5 + 7;
vector<ll> adjList[N];
bool visited[N];

void dfs(int currNode) {
    if (visited[currNode] == true) return;
    
    visited[currNode] = true;
    for (auto &u : adjList[currNode]) {
        dfs(u);
    }
}

int main()
{
    int node, edge; cin >> node >> edge;
    while (edge--) {
        int u, v; cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}