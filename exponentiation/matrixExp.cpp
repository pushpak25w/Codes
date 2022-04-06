#include<bits/stdc++.h>
#define int long long int
using namespace std;

const int mod = 1e9 ;
const int sz = 10;

class Mat {
public:
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

int seq(int* b, int* c, int n, int k) {
	Mat res;
	res.identity();
	Mat t;
	for (int i = 0; i < k; i++)t.m[0][i] = c[i];
	for (int i = 1; i < k; i++)t.m[i][i - 1] = 1;
	while (n) {
		if (n & 1)res = res * t;
		t = t * t;
		n /= 2;
	}
	int ans = 0;
	for (int i = 0; i < k; i++)ans = (ans + res.m[0][i] * b[k - i - 1]) % mod;
	return ans;
}

void solve() {
	int k;
	cin >> k;
	int n, c[k], b[k];
	for (int i = 0; i < k; i++)cin >> b[i];
	for (int i = 0; i < k; i++)cin >> c[i];
	cin >> n;
	if (n <= k)cout << b[n - 1] << endl;
	else cout << seq(b, c, n - k, k) << endl;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("/home/pushpak/Documents/C++/input.txt", "r", stdin);
	freopen("/home/pushpak/Documents/C++/output.txt", "w", stdout);
#endif

	int t ;
	cin >> t;
	while (t--)solve();
	return 0;
}