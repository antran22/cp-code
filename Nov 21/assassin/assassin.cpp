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
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m, u[maxn], v[maxn];
int num[maxn] = {}, low[maxn], cnt = 0, id[maxn], cmpcnt = 0;
stack <int> st;
vi adj[maxn];
set <int> sadj[maxn];
void tarjan (int i)
{
	num[i] = low[i] = ++cnt;
	st.push (i);
	for (int j : adj[i])
	{
		if (num[j]) low[i] = min (low[i], num[j]);
		else
		{
			tarjan (j);
			low[i] = min (low[i], low[j]);
		}
	}
	if (low[i] == num[i])
	{
		++cmpcnt;
		// cerr << cmpcnt << ' ';
		int j = 0;
		while (j != i)
		{
			j = st.top ();
			st.pop ();
			id[j] = cmpcnt;
			num[j] = low[j] = inf;
		}
	}
}
vi xadj[maxn];
void add_edge (int u, int v)
{
	cerr << u << ' ' << v << '\n';
	xadj[u].pb (v);
}
void input ()
{
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) cin >> u[i] >> v[i], adj[u[i]].pb (v[i]);
	for (int i = 1; i <= n; ++i) if (num[i] == 0) tarjan (i);
}
int visit[maxn] = {}, cti = 0, layer[maxn], match[maxn];
vi x_unmatched;
bool bfs ()
{
	queue <int> qu;
	fill (layer + 1, layer + n + 1, 0);
	for (int x : x_unmatched)
		for (int y : xadj[x]) if (!layer[y]) layer[y] = 1, qu.push (y);
	while (qu.size ())
	{
		int t = qu.front (); qu.pop ();
		int x = match[t];
		if (!x) return 1;
		for (int y : xadj[x])
			if (layer[y] == 0) layer[y] = layer[t] + 1, qu.push (y);
	}
	return 0;
}
bool found;
void dfs (int i, int lv)
{
	for (int j : xadj[i])
	{
		if (visit[j] == cti or match[j] == i or layer[j] != lv) continue;
		visit[j] = cti;
		if (!match[j]) found = 1;
		else dfs (match[j], lv + 1);
		if (found)
		{
			match[j] = i;
			return;
		}
	}
}
void max_match ()
{
	int res = 0;
	for (int i = 1; i <= m; ++i) x_unmatched.pb (i);
	while (bfs ())
	{
		++cti;
		// cerr << x_unmatched.size ();
		for (int i = x_unmatched.size () - 1; i > -1; --i)
		{
			found = 0;
			dfs (x_unmatched[i], 1);
			if (found)
				++res, x_unmatched[i] = x_unmatched.back (), x_unmatched.pop_back ();
		}
	}
	cout << res << '\n';
	// for (int i = 1; i <= n; ++i)
	// 	if (match[i]) cout << match[i] << ' ' << i << '\n';
}
void solve ()
{
	for (int i = 1; i <= m; ++i) sadj[id[u[i]]].ins (id[v[i]]);
	// for (int i = 1; i <= n; ++i) cout << id[i] << ' ';
	// for (int i = 1; i <= m; ++i) cout << id[u[i]] << ' ' << id[v[i]] << '\n';
	for (int i = 1; i <= cmpcnt; ++i)
		for (int j : sadj[i])
		add_edge (i, j);
	max_match ();
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("assassin.inp", "r", stdin);
	freopen ("assassin.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}