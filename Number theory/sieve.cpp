#include<bits/stdc++.h>
#define N 1000000
#define ll long long
using namespace std;


void primeNos(vector<int>&sieve) {
	sieve[0] = sieve[1] = 0;
	for (ll i = 2; i <=	N; i++) {
		for (ll j = i * i; j <= N; j += i) {
			sieve[j] = 0;
		}
	}
}

void solve() {
	vector<int>sieve(N, 1);
	primeNos(sieve);
	for (int i = 0; i < 100; i++) {
		if (sieve[i])cout << i << ' ';
	}
	cout << endl;
}
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("/home/pushpak/Documents/C++/input.txt", "r", stdin);
	freopen("/home/pushpak/Documents/C++/output.txt", "w", stdout);
#endif
	int t = 1;
	// cin >> t;
	while (t--)solve();
	return 0;
}