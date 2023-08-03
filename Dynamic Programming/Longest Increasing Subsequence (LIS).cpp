ll lis(ll i) {
    if (dp[i] != -1) return dp[i];
    ll ans = 1;
    for (ll j = 0; j < i; j++) {
        if (arr[j] < arr[i]) {
            ans = max(ans, lis(j) + 1);
        }
    }
    return dp[i] = ans;
}