#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin >> n;
	vector<int>primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	int m = primes.size(), ans = 0;
	for (int i = 1; i < (1 << m); i++) {
		int lcm = 1;
		for (int j = 0; j < m; j++) {
			if ((1 << j) & i)
				lcm *= primes[j];
		}
		if (__builtin_popcount(i) % 2 == 0) {
			ans -= (n / lcm);
		}
		else {
			ans += (n / lcm);
		}
	}
	cout << ans;
}
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	// cin >> t;
	while (t--)solve();
	return 0;
}