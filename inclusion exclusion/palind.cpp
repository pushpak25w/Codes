#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define int ll
#define mod 1000000007
int modPower(int a, int b)
{
	int ans = 1;
	while (b) {
		if (b % 2)ans = (ans * a) % mod;
		a = (a * a) % mod;
		b /= 2;
	}
	return ans;
}

int inv(int a) {
	return modPower(a, mod - 2);
}

int sumgp(int a, int r, int n) {
	int ans = modPower(r, n) - 1;
	ans *= inv(r - 1);
	ans %= mod;
	ans *= a;
	ans %= mod;
	return (ans + mod) % mod;
}

void solve() {
	int n;
	cin >> n;
	int ans1 = sumgp(1, inv(26), (n + 1) / 2);
	int ans2 = sumgp(inv(26), inv(26), n / 2);
	int ans = (ans1 + ans2) % mod;
	cout << ans << endl;
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}