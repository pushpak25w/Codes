#include<bits/stdc++.h>
using namespace std;

int binaryMul(int a, int b, int c) {
	int res = 0;
	while (b) {
		if (b & 1)res += a, res %= c;
		a *= 2;
		a %= c;
		b /= 2;
	}
	return res;
}

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << binaryMul(a, b, c);

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