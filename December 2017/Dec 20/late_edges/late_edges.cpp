#include <bits/stdc++.h>
using namespace std;
#define whole(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define ins insert
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
struct edge
{
	int v, t;
};
vector <edge> adj[maxn];
bool vst[maxn];
void dfs (int i)
{
	vst[i] = 1;
	for (edge j : adj[i])
	{
		if (vst[j.v]) continue;
		dfs (j.v);
	}
}
void input ()
{
	cin >> n >> m;
	int u, v, t;
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v >> t;
		adj[u].pb (edge {v, t});
		adj[v].pb (edge {u, t});
	}
	for (int i = 1; i <= n; ++i)
	{
		sort (whole (adj[i]), [] (edge x, edge y)
		{
			return x.t < y.t;
		});
	}
}
set <int> before, after;
int t = 0;
void bfs ()
{
	while (true)
	{
		after.clear ();
		for (int i : before)
		{
			if (i == n)
			{	
				cout << t;
				return;
			}
			for (edge j : adj[i])
			{
				if (j.t > t) break;
				
				after.ins (j.v);
			}
		}
		++t;
		before = after;
	}
}
void solve ()
{
	dfs (1);
	if (!vst[n])
	{
		cout << -1;
		return;
	}
	before.ins (1);
	bfs ();
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	freopen ("late_edges.inp", "r", stdin);
	freopen ("late_edges.out", "w", stdout);
	cin.tie (NULL);
	cout.tie (NULL);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}