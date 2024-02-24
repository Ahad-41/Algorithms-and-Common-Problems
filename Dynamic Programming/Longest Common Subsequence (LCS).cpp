// print the lcs length
ll lcs(ll i, ll j, string &s1, string &s2) {
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
        
    ll ans = lcs(i-1, j, s1, s2);
    ans = max(ans, lcs(i, j-1, s1, s2));
    ans = max(ans, lcs(i-1, j-1, s1, s2) + (s1[i] == s2[j]));
    return dp[i][j] = ans;
}

// print the lcs string
string lcs(string a, string b) {
    ll m = a.length(), n = b.length();
    a = '@' + a;
    b = '@' + b;
    
    ll dp[m+1][n+1];
    memset(dp, 0, sizeof(dp));

    for (ll i = 1; i <= m; i++) {
        for (ll j = 1; j <= n; j++) {
            if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    ll i = m, j = n;
    string ans;
    while (i > 0 && j > 0) {
        if (a[i] == b[j]) {
            ans = a[i] + ans;
            i--;
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }

    return ans;
}
