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
int n, k, m, crit_edge, u, v;
vi adj[maxn];
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
		// cin >> u >> v;
		FI (u); FI (v);
		adj[u].pb (v);
		adj[v].pb (u);
	}
}
int low[maxn], num[maxn] = {}, cnt = 0;
bool crit_vertex [maxn] = {};
void tarjan (int i, int p)
{
	low[i] = num[i] = ++cnt;
	int child = 0;
	for (int j : adj[i])
	{
		if (j == p) continue;
		if (num[j]) low[i] = min (low[i], num[j]);
		else 
		{
			++child;
			tarjan (j, i);
			low[i] = min (low[i], low[j]);
			if (low[j] >= num[j]) ++crit_edge;
			if (p == i)
			{
				if (child >= 2) crit_vertex[i] = 1;
			}
			else 
			{
				if (low[j] >= num[i]) crit_vertex [i] = 1;
			}
		}
	}
}
void solve ()
{
	for (int i = 1; i <= n; ++i)
	{
		if (!num[i]) tarjan (i, i);
	}
	int x = 0;
	for (int i = 1; i <= n; ++i) if (crit_vertex[i]) ++x;
	cout << x << ' ' << crit_edge;
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("compnet.inp", "r", stdin);
	freopen ("compnet.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}