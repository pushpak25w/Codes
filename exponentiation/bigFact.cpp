#include<bits/stdc++.h>
using namespace std;

void multiply(vector<int>&a, int n, int &size) {
	int carry = 0;
	for (int i = 0; i < size; i++) {
		int prod = a[i] * n + carry;
		carry = prod / 10;
		a[i] = prod % 10;
	}
	while (carry) {
		a[size++] = carry % 10;
		carry /= 10;
	}
}

void bigFact(int n) {
	vector<int>a(1000, 0);
	a[0] = 1;
	int size = 1;
	for (int i = 2; i <= n; i++) {
		multiply(a , i, size);
	}
	for (int i = size - 1; i >= 0; i--) {
		cout << a[i];
	}
}

void solve() {
	int n;
	cin >> n;
	bigFact(n);
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