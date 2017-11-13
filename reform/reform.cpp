//code.cpp
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
struct edge
{
	int v, id;
	edge () {}
	edge (int vv, int iid)
	{
		v = vv;
		id = iid;
	}
};
vector <edge> adj[maxn];
int low[maxn], num[maxn] = {}, cnt = 0, id[maxn], cmpcnt = 0, cmpnum[maxn] = {};
int h[maxn], cnum[maxn] = {}, p[maxn], crit_cnt = 0;
bool crit[maxn] = {};
void tarjan (int i)
{
	low[i] = num[i] = ++cnt;
	id[i] = cmpcnt;
	++cmpnum[cmpcnt];
	for (edge &x : adj[i])
	{
		int j = x.v;
		if (j == p[i]) continue;
		if (num[j]) low[i] = min (low[i], num[j]);
		else
		{
			h[j] = h[i] + 1;
			p[j] = i;
			tarjan (j);
			low[i] = min (low[i], low[j]);
			cnum[i] += cnum[j];
			if (low[j] >= num[j]) ++crit_cnt, crit[x.id] = 1;
		}
	}
	cnum[i] ++;
}
int u[maxn], v[maxn];
void input ()
{
	cin >> n >> m;
	for (int i = 1; i <= m; ++i)
		cin >> u[i] >> v[i], adj[u[i]].pb (edge (v[i], i)), adj[v[i]].pb (edge (u[i], i));
	for (int i = 1; i <= n; ++i)
		if (num[i] == 0) ++cmpcnt, p[i] = i, h[i] = 1, tarjan (i);
}
ll res = 0;
void check ()
{
	for (int i = 1; i <= m; ++i)
	{
		// cerr << u[i] << ' ' << v[i] << ' ' << crit[i] << '\n';
		if (crit[i])
		{
			if (h[v[i]] < h[u[i]]) swap (v[i], u[i]);
			ll a = cnum[v[i]], b = n - a;
			// cout << a << ' ' << b << '\n';
			res += a * b - 1;
		}
		else
		{
			res += ((ll) (n) * (n - 1)) / 2 - m;
		}
	}
}
bool vst[maxn];
void solve ()
{
	if (cmpcnt > 2)
	{
		cout << 0;
		return;
	}
	if (cmpcnt == 2)
	{
		// cerr << cmpnum[1] << ' ' << cmpnum[2] << ' ' << crit_cnt;
		cout << ((ll) (cmpnum[1])) * cmpnum[2] * (m - crit_cnt);
	}
	else if (cmpcnt == 1)
	{
		check ();
		cout << res;
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
	freopen ("reform.inp", "r", stdin);
	freopen ("reform.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}