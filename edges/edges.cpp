//code.cpp
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
typedef pair<int,int> edge;
#define u first
#define v second
typedef pair<ll,edge> wedge;
#define ww first
#define ee second
typedef pair<int,ll> wadj;
#define av first
#define aw second
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9;
int n, k, m;
vector <edge> e;
vector <wedge> we;
vi adj[maxn];
ll sum = 0;
bool in[maxn] = {};
void input ()
{
	int inu, inv;
	ll inw;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> inu >> inv;
		e.pb (mp (inu, inv));
		adj[inu].pb (inv);
	}
	cin >> m;
	for (int i = 1; i <= m; ++i)
	{
		cin >> inu >> inv >> inw;
		if (inw <= 0) e.pb (mp (inu, inv)), sum += inw;
		else we.pb (mp (inw, mp (inu, inv)));
	}
}
int num[maxn], low[maxn], cnt = 0, id[maxn], ccmp = 0;
stack <int> st;
void tarjan (int i)
{
	num[i] = low[i] = ++cnt;
	st.push (i);
	for (int j : adj[i])
	{
		if (num[j]) low[i] = min (low[i], num[j]);
		else tarjan (j), low[i] = min (low[i], low[j]);
	}
	if (low[i] == num[i])
	{
		int j;
		++ccmp;
		do
		{
			j = st.top ();
			st.pop ();
			id[j] = ccmp;
			low[i] = num[j] = inf;
		}
		while (j != i);
	}
}
vi dag[maxn];
int in_deg [maxn] = {}, out_deg [maxn] = {};
vi topo_order, zr;
vector <wadj> adj2[maxn];
void topo_sort ()
{
	while (zr.size ())
	{
		int i = zr.back ();
		zr.pop_back ();
		topo_order.pb (i);
		for (int j : dag[i])
			if (--in_deg[j] == 0) zr.pb (j);
	}
}
ll f[maxn];
void solve ()
{
	for (int i = 1; i <= n; ++i) if (num[i] == 0) tarjan (i);
	for (edge x : e)
	{
		if (id[x.v] != id[x.u]) dag[id[x.u]].pb (id[x.v]);
		++in_deg [id[x.v]];
		++out_deg [id[x.u]];
	}
	int x = 0, y = 0;
	for (int i = 1; i <= ccmp; ++i)
	{
		if (in_deg[i] == 0) x = i, zr.pb (i);
		if (out_deg[i] == 0) y = i;
	}
	for (wedge y : we)
	{
		int i = id[y.ee.u], j = id[y.ee.v];
		adj2[i].pb (mp (j, y.ww));
	}
	topo_sort ();
	fill (f + 1, f + ccmp + 1, inff);
	f[x] = 0;
	for (int i : topo_order)
	{
		for (auto j : adj2[i])
			f[i] = min (f[i], f[j.av] + j.aw);
	}
	if (f[y] < inff)
	{
		cout << "YES\n" << f[y] + sum;
	}
	else cout << "NO";
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("edges.inp", "r", stdin);
	freopen ("edges.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}