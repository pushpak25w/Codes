#include<bits/stdc++.h>
#define int long long int
using namespace std;

const int mod = 1e9 + 7;
const int sz = 2;

struct Mat {
	int m[sz][sz];
	Mat() {
		memset(m, 0, sizeof(m));
	}
	void identity() {
		for (int i = 0; i < sz; i++) {
			m[i][i] = 1;
		}
	}
	Mat operator* (Mat a) {
		Mat res;
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				for (int k = 0; k < sz; k++) {
					res.m[i][j] += m[i][k] * a.m[k][j];
					res.m[i][j] %= mod;
				}
			}
		}
		return res;
	}
};

int fib(int n) {
	Mat res;
	res.identity();
	Mat t;
	t.m[0][0] = t.m[0][1] = t.m[1][0] = 1;
	if (n <= 2)return 1;
	n -= 2;
	while (n) {
		if (n & 1)res = res * t;
		t = t * t;
		n /= 2;
	}
	return (res.m[0][0] + res.m[0][1]) % mod;
}

void solve() {
	int n;
	cin >> n;
	cout << fib(n) << endl;
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