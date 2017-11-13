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
#define sc second
#define _(a) #a << " : " << (a)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m, s, t;
struct edge
{
	int u, v, id; ll c;
	edge () {}
	edge (int uu, int vv, int iid, ll ww)
	{
		id = iid;
		u = uu;
		v = vv;
		c = ww;
	}
};
vector <edge> edge_list;
struct ajc
{
	int v, id;
	ajc () {}
	ajc (int vv, int iid)
	{
		v = vv, id = iid;
	}
};
vector <ajc> adj[maxn];
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
ll cf[maxn];
void input ()
{
	// cin >> n >> m >> s >> t;
	FI (n), FI (m), FI (s), FI (t);
	int u, v, w, id = -1;
	for (int i = 1; i <= m; ++i)
	{
		// cin >> u >> v >> w;
		FI (u);
		FI (v);
		FI (w);
		++id;
		edge_list.pb (edge (u, v, id, w));
		adj[u].pb (ajc (v, id));
		cf[id] = w;
		++id;
		adj[v].pb (ajc (u, id));
		cf[id] = 0;
	}
}
pair <int, int> pre[maxn];
bool bfs ()
{
	fill (pre + 1, pre + n + 1, mp (-1, 0));
	queue <int> qu;
	qu.push (s);
	pre[s] = mp (0, 0);
	while (qu.size ())
	{
		int i = qu.front ();
		qu.pop ();
		for (ajc x : adj[i])
		{
			int j = x.v, id = x.id;
			if (cf[id] <= 0 or pre[j].ft != -1) continue;
			pre[j] = mp (i, id);
			qu.push (j);
		}
	}
	return (pre[t].ft != -1);
}
ll flow_inc, flow_sum = 0;
void find_augmenting_path ()
{
	flow_inc = inff;
	int j = t;
	while (true)
	{
		int i = pre[j].ft, id = pre[j].sc;
		if (i == 0) return;
		flow_inc = min (flow_inc, cf[id]);
		j = i;
	}
}
void augment_graph ()
{
	int j = t;
	while (true)
	{
		int i = pre[j].ft, id = pre[j].sc;
		if (i == 0) break;
		cf[id] -= flow_inc;
		cf[id ^ 1] += flow_inc;
		j = i;
	}
	flow_sum += flow_inc;
}
void solve ()
{
	while (bfs ())
	{
		find_augmenting_path ();
		augment_graph ();
	}
	cout << flow_sum << '\n';
	for (edge x : edge_list)
	{
		cout << x.c - cf[x.id] << '\n';
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
	freopen ("flow.inp", "r", stdin);
	freopen ("flow.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}