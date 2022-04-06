#include<bits/stdc++.h>
#define N 1000000
#define ll long long
using namespace std;

vector<int>sieve(N, 1);
vector<int>csum(N);
void primeNos() {
	sieve[0] = sieve[1] = 0;
	for (ll i = 2; i <=	N; i++) {
		for (ll j = i * i; j <= N; j += i) {
			sieve[j] = 0;
		}
	}
	csum[0] = 0;
	for (ll i = 1; i <= N; i++) {
		if (sieve[i] != 0) {
			csum[i] = csum[i - 1] + 1;
		}
		else csum[i] = csum[i - 1];
	}
}

void solve() {
	int a, b;
	cin >> a >> b;
	// for (int i = 0; i < 100; i++) {
	// 	cout << csum[i] << ' ';
	// }
	// cout << endl;
	cout << csum[b] - csum[a - 1] << endl;
}
int32_t main() {
	primeNos();
#ifndef ONLINE_JUDGE
	freopen("/home/pushpak/Documents/C++/input.txt", "r", stdin);
	freopen("/home/pushpak/Documents/C++/output.txt", "w", stdout);
#endif
	int t = 1;
	// cin >> t;
	while (t--)solve();
	return 0;
}