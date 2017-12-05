#include <bits/stdc++.h>
using namespace std;
#define whole(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define ins insert
#define ft first
#define sd second
#define _(a) #a << " : " << (a)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m;
ll gg = 0;
vi adj[maxn], xadj[maxn];
int par[maxn], a[maxn];
void input ()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i], gg += a[i];
	int u, v;
	for (int i = 1; i < n; ++i) cin >> u >> v, xadj[u].pb (v), xadj[v].pb (u);
}
int curr_cap [maxn] = {};
int res = 0, end_leaf;
bool first_dfs (int i, int p)
{
	for (int j : xadj[i])
	{
		if (j != p)
		{
			par[j] = i;
			adj[i].pb (j);
			first_dfs (j, i);
		}
	}
}
void dfs (int i, int x)
{
	if (curr_cap[i] < a[i]) ++x;
	else --x;
	if (adj[i].size () == 0)
	{
		if (curr_cap[i] >= 1) return;
		if (res < x) res = x, end_leaf = i;
		return;
	}
	for (int j : adj[i])
		dfs (j, x);
}
bool augment ()
{
	res = 0, end_leaf = 0;
	dfs (1, 0);
	if (res == 0) return 0;
	gg -= res;
	int i = end_leaf;
	while (i != 0)
	{
		++curr_cap[i];
		i = par[i];
	}
	return 1;
}
void solve ()
{
	first_dfs (1, 1);
	while (augment ());
	cout << gg;
	// for (int i : adj[]) cout << i << ' ';
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("tree.inp", "r", stdin);
	freopen ("tree.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}