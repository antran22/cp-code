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
int n, k, m;
void input ()
{
	cin >> n >> k;
}
struct edge
{
	int u, v, w;
};
vector <edge> ed;
void solve ()
{
	for (int i = 1; i <= n - 1; ++i)
	{
		// cout << i << ' ' << i + 1 << ' ' <<i << '\n';
		ed.pb (edge {i, i + 1, i});
	}
	int x = n - 1 - k, cnt = n, e = n, t = n - 2;
	for (int i = 1; i <= x; ++i)
	{
		// cout << e << ' ' << t << ' ' << cnt ++ << '\n';
		if (t == 0) 
		{
			cout << -1;
			exit (0);
		}
		ed.pb (edge {e, t, cnt++});
		--t;
		if (t == 0)
		{
			--e;
			t = e - 2;
		}
	}
	cout << ed.size () << '\n';
	for (edge x : ed)
	{
		cout << x.u << ' ' << x.v << ' ' << x.w << '\n';
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
	freopen ("spanning_tree.inp", "r", stdin);
	freopen ("spanning_tree.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}