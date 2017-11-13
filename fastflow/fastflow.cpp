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
int n, k, m, s, t, u, v;
ll c[maxn];
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
ll cf[maxn];
int id = -1;
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
	FI (s);
	FI (t);
	int c;
	for (int i = 1; i <= m; ++i)
	{
		// cin >> u >> v >> c[i];
		FI (u);
		FI (v);
		FI (c);
		adj[u].pb (ajc (v, ++id));
		cf[id] = c;
		adj[v].pb (ajc (u, ++id));
		cf[id] = 0;
	}
}
int dist[maxn] = {};
bool bfs ()
{
	queue <int> qu;
	fill (dist + 1, dist + n + 1, -1);
	qu.push (s);
	dist[s] = 1;
	while (qu.size ())
	{
		int i = qu.front ();
		qu.pop ();
		if (i == t) return 1;
		for (ajc j : adj[i])
		{
			if (dist[j.v] == -1 and cf[j.id] > 0)
			{
				dist[j.v] = dist[i] + 1;
				qu.push (j.v);
			}
		}
	}
	return dist[t] != -1;
}
int vst[maxn] = {}, dfs_time = 0;
ll send_flow (int i, ll flow)
{
	if (i == t) return flow;
	if (vst[u] != dfs_time)
		vst[i] = t;
	else return 0;
	for (ajc j : adj[i])
	{
		if (cf[j.id] > 0)
		{
			if (vst[j.v] != dfs_time and dist[j.v] == dist[i] + 1)
			{
				ll new_flow = send_flow (j.v, min (flow, cf[j.id]));
				if (new_flow == 0) continue;
				cf[j.id] -= new_flow;
				cf[j.id ^ 1] += new_flow;
				return new_flow;
			}
		}
	}
	return 0;
}
void solve ()
{
	ll total_flow = 0;
	while (bfs ())
	{
		++dfs_time;
		ll flow = send_flow (s, inf);
		// if (flow == 0) break;
		total_flow += flow;
	}
	cout << total_flow;
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("fastflow.inp", "r", stdin);
	freopen ("fastflow.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}