#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> lps(string s) {
    ll n = s.size();
    vector<ll> lpsArray(n);
    ll j = 0;
    for (ll i = 1; i < n; i++) {
        while (j > 0 and s[j] != s[i]) j = lpsArray[j-1];
        if (s[j] == s[i]) j++;
        lpsArray[i] = j;
    }   

    return lpsArray;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    vector<ll> v = lps(s);

    for (auto &u : v) cout << u << " ";
}