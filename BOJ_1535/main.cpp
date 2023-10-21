#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

vvi dp;
int n;
vi ls;
vi js;

void solve() {
	for (auto i = 1; i <= n; ++i) {
		for (auto j = 1; j < 100; ++j) {
			if (ls[i] <= j) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - ls[i]] + js[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;

	dp = vvi(n + 1, vi(100, 0));

	ls = vi(n + 1, 0);
	for (auto i = 1; i <= n; ++i) {
		cin >> ls[i];
	}

	js = vi(n + 1, 0);
	for (auto i = 1; i <= n; ++i) {
		cin >> js[i];
	}

	solve();

	cout << dp[n][99];

	return 0;
}