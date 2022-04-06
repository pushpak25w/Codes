#include<bits/stdc++.h>
using namespace std;

int tsp(vector<vector<int>>&dist, int setOfCitites, int city, int n, vector<vector<int>>&dp) {
	//base case
	if (setOfCitites == (1 << n) - 1)
		return dist[city][0];
	if (dp[setOfCitites][city] != -1)return dp[setOfCitites][city];
	//explore remaining
	int ans = INT_MAX;
	for (int i = 0; i < n; i++) {
		if ((1 << i & setOfCitites) == 0) {
			int subProb = dist[city][i] + tsp(dist, setOfCitites | (1 << i), i, n, dp);
			ans = min(ans, subProb);
		}
	}
	return dp[setOfCitites][city] = ans;
}


int main() {
	vector<vector<int>> dist = {
		{0, 20, 42, 25},
		{20, 0, 30, 34},
		{42, 30, 0, 10},
		{25, 34, 10, 0}
	};
	int n = 4;
	vector<vector<int>>dp(1 << n, vector<int>(n, -1));
	cout << tsp(dist, 1, 0, n, dp) << endl;

}