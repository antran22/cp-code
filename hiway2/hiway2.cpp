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
#define sd secondz
#define _(a) #a << " : " << (a)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m, s, t, cf[maxn], id = -1;
struct ajc
{
	int v, id, w;
	ajc () {}
	ajc (int vv, ll ww, int iid)
	{
		v = vv, id = iid;
		w = ww;
	}
};
vector <ajc> adj[maxn];
void input ()
{
	cin >> n >> m >> s >> t;
	int u, v, w;
	for (int i = 1; i <= m; ++i)
	{
		cin >> u >> v >> w;
		adj[u].pb (ajc (v, w, ++id));
		cf[id] = 1;
		adj[v].pb (ajc (u, -w, ++id));
		cf[id] = 0;
		adj[v].pb (ajc (u, w, ++id));
		cf[id] = 1;
		adj[u].pb (ajc (v, -w, ++id));
		cf[id] = 0;
	}
}
struct path
{
	int v; ll w;
	path () {}
	path (int vv, ll ww)
	{
		v = vv; w = ww;
	}
};
struct prv
{
	int v, id;
	prv () {}
	prv (int vv, int iid)
	{
		v = vv; id = iid;
	}
};
struct cmp
{
	bool operator () (const path &a, const path &b)
	{
		return a.w > b.w;
	}
};
typedef priority_queue <path,vector <path>,cmp> minheap;
ll dist[maxn], p[maxn];
prv pre[maxn];
bool dijkstra ()
{
	minheap pq;
	fill (dist + 1, dist + n + 1, inff);
	fill (pre + 1, pre + n + 1, prv (-1, 0));
	pq.push (path (s, 0));
	pre[s] = prv (0, 0);
	dist[s] = 0;
	while (pq.size ())
	{
		path g = pq.top ();
		pq.pop ();
		if (dist[g.v] != g.w) continue;
		int i = g.v;
		for (int it = 0; it < adj[i].size (); ++it)
		{
			ajc x = adj[i][it];
			if (cf[x.id] <= 0) continue;
			int j = x.v;
			ll w = x.w + p[i] - p[j];
			if (dist[j] > dist[i] + w)
			{
				dist[j] = dist[i] + w;
				pq.push (path (j, dist[j]));
				pre[j] = prv (i, x.id);
			}
		}
	}
	return pre[t].v != -1;
}
int augment ()
{
	int j = t;
	while (1)
	{
		if (pre[j].v == 0) break;
		int id = pre[j].id;
		cf[id] --;
		cf[id ^ 1] ++;
		j = pre[j].v;
	}
	// for (int i = 1; i <= n; ++i) cout << pre[i].v << ' ' << p[i] << ' ' << dist[i] << '\n', p[i] += dist[i];
	// cout << '\n';
}
void solve ()
{
	ll res = 0;
	for (int i = 1; i <= 2; ++i)
	{
		if (!dijkstra ())
		{
			cout << -1;
			return;
		}
		res += dist[t] - p[s] + p[t];
		augment ();
	}
	cout << res;
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("hiway2.inp", "r", stdin);
	freopen ("hiway2.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}