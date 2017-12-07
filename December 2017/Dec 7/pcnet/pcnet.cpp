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
int n, k, m, s, t;
int check[maxn] = {};
vi adj[maxn];
void input ()
{
	cin >> n >> m;
	int p;
	for (int i = 1; i <= m; ++i)
	{
		cin >> p;
		vi c;
		int cc;
		for (int j = 1; j <= p; ++j)
			cin >> cc, c.pb (cc), ++check[cc];
		for (int j = 0; j < p; ++j)
			for (int k = j + 1; k < p; ++k)
			{
				adj[c[j]].pb (c[k]);
				adj[c[k]].pb (c[j]);
			}
	}
	cin >> s >> t;
}
struct path
{
	int v, w;
};
struct cmp
{
	bool operator () (const path &a, const path &b)
	{
		return a.w > b.w;
	}
};
typedef priority_queue <path,vector <path>,cmp> minheap;
int d[maxn];
void solve ()
{
	fill_n (d + 1, n, inf);
	minheap pq;
	pq.push (path {s, 0});
	d[s] = 0;
	while (pq.size ())
	{
		path u = pq.top ();
		pq.pop ();
		if (d[u.v] != u.w) continue;
		for (int i : adj[u.v])
		{
			int g = u.w + (check[i] >= 2);
			if (d[i] > g)
			{
				d[i] = g;
				pq.push (path {i, g});
			}
		}
	}
	if (d[t] < inf)
		cout << d[t];
	else cout << -1;
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("pcnet.inp", "r", stdin);
	freopen ("pcnet.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}