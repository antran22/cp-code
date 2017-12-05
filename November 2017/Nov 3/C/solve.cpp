#include <string>
#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;
const int MAXN = 55;
const ll inf = 1e18;

ll G[MAXN * 2][MAXN * 2];
ll f[MAXN][MAXN][105];
int N, M, charges;
int chk[MAXN][MAXN][105];

ll& op(ll &x, ll y) { return x = min(x, y); }

ll solve(int i, int j, int steps, int level) {
	if (!steps) return G[i][j];
	if (steps == 1) return G[i][j + N];
	if (chk[i][j][level]) return f[i][j][level]; chk[i][j][level] = 1;
	ll &ans = f[i][j][level] = inf;
	if (steps & 1) {
		for (int k = 1; k <= N; ++k) op(ans, solve(i, k, steps - 1, level + 1) + G[k][j + N]);
	}
	else for (int k = 1; k <= N; ++k)
		op(ans, solve(i, k, steps / 2, level + 1) + solve(k, j, steps / 2, level + 1));
	// cout << i << ' ' << j << ' ' << steps << ' ' << ans << endl;
	return ans;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= 2 * N; ++i) 
		for (int j = 1; j <= 2 * N; ++j)
			if (i == j || j == i + N) G[i][j] = 0;
			else G[i][j] = inf;
	for (int i = 0; i < M; ++i) {
		int u, v; ll w;
		cin >> u >> v >> w;
		op(G[u][v], w); op(G[u][v + N], -w); op(G[u + N][v + N], w);
	} 
	cin >> charges;
	for (int k = 1; k <= 2 * N; ++k)
		for (int i = 1; i <= 2 * N; ++i)
			for (int j = 1; j <= 2 * N; ++j) op(G[i][j], G[i][k] + G[k][j]);
	cout << solve(1, N, charges, 0);
}