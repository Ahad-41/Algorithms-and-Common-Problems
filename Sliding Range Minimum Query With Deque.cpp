#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, m; cin >> n >> m;
    int arr[n];
    for (auto &u : arr) cin >> u;
    
    vector <int> ans;
    deque<pair<int, int>> dq;


    for (int i = 0; i < n; i++) {
        while (!dq.empty() and dq.front().first >= arr[i]) {
            dq.pop_front();
        }

        dq.push_front({arr[i], i});

        while (!dq.empty() and i - dq.back().second+1 > m) {
            dq.pop_back();
        }
        
        if (i >= m-1) ans.push_back(dq.back().first);
        
    }

    for (auto &u : ans) cout << u << " ";
    cout << endl;
}  