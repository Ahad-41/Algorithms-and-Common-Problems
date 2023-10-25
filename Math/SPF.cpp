const ll N = 1e6+7;
bool check[N];
ll spf[N];

void sieve() {
	for (ll i = 2; i < N; i += 2) spf[i] = 2;
	for (ll i = 3; i < N; i += 2) {
		if (!check[i]) {
			spf[i] = i;
			for (ll j = i; j*i < N; j += 2) {
				if (!check[j*i]) {
            spf[j*i] = i;
            check[j*i] = true;
        }
			}
		}
	}
}
