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
const int inf = 1e9, maxn = 2001;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m;
int p, q[maxn], c[maxn], res[maxn];
vi adj[maxn], ja[maxn];
int cnt[maxn];
int hihi (int i)
{
	int res = 0;
	while (i != 0)
	{
		res += cnt[i];
		i = q[i];
	}
	return res;
}
void dfs (int i)
{
	for (int j : ja[i]) cnt[j] ++;
	res[i] = hihi (i);
	for (int j : adj[i])
		dfs (j);
	for (int j : ja[i]) cnt[j] --;
}
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
	FI (n), FI (m);
	for (int i = 1; i <= n; ++i)
	{
		FI (p), FI (k), adj[p].pb (i);
		q[i] = k;
	}
	int s, r;
	for (int i = 1; i <= m; ++i)
	{
		FI (s), FI (r);
		ja[s].pb (r);
	}
}
void solve ()
{
	dfs (0);
	for (int i = 1; i <= n; ++i) printf("%d\n", res[i]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("spy.inp", "r", stdin);
	freopen ("spy.out", "w", stdout);
	input ();
	solve ();
}