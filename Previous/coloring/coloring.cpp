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
typedef pair <int, int> pii;
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m, a;
vi pos[maxn];
int adj[maxn];
void input ()
{
	cin >> n;
	for (int i = 1; i <= 2 * n; ++i)
		cin >> a, pos[a].pb (i);
	for (int i = 1; i <= n; ++i)
	{
		int a = pos[i][0], b = pos[i][1];
		adj[a] = b;
		adj[b] = a;
	}
}
int po (int a)
{
	if (a > n) return a - n;
	return a;
}
bool pre (int a, int b)
{
	return po (a) < po (b);
}
ll f[maxn];
void solve ()
{
	f[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		int j = i + n;
		if (pre (adj[i], i) or pre(adj[j], j)) f[i] = f[i - 1];
		else f[i] = f[i - 1] * 2;
	}
	cout << f[n];
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("coloring.inp", "r", stdin);
	freopen ("coloring.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}