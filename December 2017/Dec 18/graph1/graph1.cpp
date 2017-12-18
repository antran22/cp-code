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
int comp[maxn] = {}, compcnt = 0;
set <pair <int,int>> edge;
vi adj[maxn];
void dfs (int i)
{
	comp[i] = compcnt;
	for (int j : adj[i])
	{
		if (!comp[j])
			dfs (j);
	}
}
int u, v;
void input ()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v;
		edge.ins (mp (u, v));
		edge.ins (mp (v, u));
		adj[u].pb (v);
		adj[v].pb (u);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!comp[i]) 
		{
			compcnt ++;
			dfs (i);
		}
	}
	cout << compcnt << '\n';
}
void solve ()
{
	for (int i = 1; i <= k; ++i)
	{
		cin >> u >> v;
		if (edge.find (mp (u, v)) != edge.end ()) cout << "2\n";
		else cout << (comp[u] == comp[v]) << '\n';
	}
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	// freopen ("graph1.inp", "r", stdin);
	// freopen ("graph1.out", "w", stdout);
	input ();
	solve ();
}