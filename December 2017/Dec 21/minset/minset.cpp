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
const int inf = 1e9, maxn = 1e6 + 1, mod = 1e9 + 7;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m;
struct ajc
{
	int v, id;
};
vector <ajc> adj[maxn];
int u[maxn], v[maxn];
void FI(int &x)
{
    register int c = getchar();
    x = 0;
    bool neg = 0;
    for(;(c < 48 or c > 57) && c != '-';c = getchar());
    if (c == '-') neg = 1, c = getchar();
    for(; c > 47 && c < 58;c = getchar()) x = (x<<1) + (x<<3) + c - 48;
    if(neg) x = -x;
}
void input ()
{
	// cin >> n >> m;
	FI (n);
	FI (m);
	for (int i = 1; i <= m; ++i)
	{
		// cin >> u[i] >> v[i];
		FI (u[i]), FI (v[i]);
		adj[u[i]].pb (ajc {v[i], i});
		adj[v[i]].pb (ajc {u[i], i});
	}
}
int low[maxn], num[maxn], cnt = 0;
bool crit[maxn];
bool trav[maxn];
void tarjan (int i)
{
	low[i] = num[i] = ++cnt;
	for (ajc x : adj[i])
	{
		int j = x.v;
		if (trav[x.id]) continue;
		trav[x.id] = 1;
		if (num[j]) low[i] = min (low[i], num[j]);
		else
		{
			tarjan (j);
			low[i] = min (low[i], low[j]);
			if (num[j] <= low[j]) crit[x.id] = 1;
		}
	}
}
struct disjoint_set_union
{
	vi lab;
	disjoint_set_union ()
	{
		lab.resize (maxn, -1);
	}
	int root (int i)
	{
		return lab[i] < 0 ? i : lab[i] = root (lab[i]);
	}
	bool _union (int u, int v)
	{
		int ru = root (u), rv = root (v);
		if (ru == rv) return 0;
		if (lab[ru] > lab[rv]) swap (ru, rv);
		lab[ru] += lab[rv];
		lab[rv] = ru;
	}
};
disjoint_set_union dsu;
set <int> tadj[maxn];
void solve ()
{
	tarjan (1);
	for (int i = 1; i <= m; ++i)
	{
		if (!crit[i]) dsu._union (u[i], v[i]);
	}
	for (int i = 1; i <= m; ++i)
	{
		if (crit[i]) 
		{
			tadj[dsu.root (u[i])].ins (dsu.root (v[i]));
			tadj[dsu.root (v[i])].ins (dsu.root (u[i]));
		}
	}
	ll res = 1;
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (dsu.lab[i] < 0 and tadj[i].size () <= 1) ++cnt, res = (res * (-dsu.lab[i])) % mod;
	}
	cout << cnt << ' ' << res;
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("minset.inp", "r", stdin);
	freopen ("minset.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}