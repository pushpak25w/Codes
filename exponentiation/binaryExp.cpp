#include<bits/stdc++.h>
using namespace std;

int binaryExp(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1)res *= a;
		a *= a;
		b /= 2;
	}
	return res;
}

void solve() {
	int a, b;
	cin >> a >> b;
	cout << binaryExp(a, b);

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