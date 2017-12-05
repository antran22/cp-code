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
vi adj[maxn], posa[maxn];
void make_edge (int i, int j)
{
	adj[i].pb (j);
	adj[j].pb (i);
}
int a;
void input ()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a, posa[a].pb (i), make_edge (i, i + n);
	for (int i = 1; i <= n; ++i) cin >> a, posa[a].pb (i + n);
	for (int i = 1; i <= n; ++i) make_edge (posa[i][0], posa[i][1]);
}
bool vst[maxn];
void dfs (int i)
{
	if (vst[i]) return;
	vst[i] = 1;
	for (int j : adj[i])
	{
		if (vst[j]) continue;
		dfs (j);
	}
}
void solve ()
{
	ll res = 0;
	for (int i = 1; i <= n * 2; ++i) if (!vst[i]) res ++, dfs (i);
	cout << ((1LL) << res);
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("kol.inp", "r", stdin);
	freopen ("kol.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}