#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void floydWarshall(ll v) { // Here v = number of vertex;
    for (ll k = 0; k < v; k++) {
        for (ll i = 0; i < v; i++) {
            for (ll j = 0; j < v; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) and (dist[k][j] != INF and dist[i][k] != INF)) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
