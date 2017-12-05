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
const ld eps = 1e-9;
int n, k, m, s;
int in[100][100];
struct tab
{
	int id[30];
	void operator = (tab x)
	{
		for (int i = 1; i <= m; ++i)
			id[i] = x.id[i];
	}
	bool operator == (tab x)
	{
		for (int i = 1; i <= m; ++i)
			for (int j = 1; j <= n; ++j)
				if (in[id[i]][j] != in[x.id[i]][j]) return 0;
		return 1;
	}
} a, b;
void t_sort (tab &g, int i)
{
	stable_sort (g.id + 1, g.id + m + 1, [i] (int x, int y)
	{
		return in[x][i] < in[y][i];
	});
}
vi ac;
void input ()
{
	cin >> m >> n >> s;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> in[i][j];
	vi pos (110, 0);
	for (int i = 1; i <= s; ++i)
		cin >> k, pos[k] = i;
	vi srt (110, 0);
	for (int i = 1; i <= n; ++i)
		if (pos[i]) srt[pos[i]] = i;
	for (int i : srt) if (i != 0) ac.pb (i);
}
void print (tab &x)
{
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
			cout << in[x.id[i]][j] << ' ';
		cout << '\n';
	}
}
bool pick[11] = {};
vi mov;
int best = 0;
void attempt (tab g, int d)
{
	if (d >= best) return;
	if (g == b)
	{
		best = d;
		ac = mov;
		// cerr << d << ' ';
		return;
	}
	for (int i = 1; i <= n; ++i)
		if (!pick[i])
		{
			tab h = g;
			t_sort (h, i);
			pick[i] = 1;
			mov.pb (i);
			attempt (h, d + 1);
			mov.pop_back ();
			pick[i] = 0;
		}
}
void solve ()
{
	best = ac.size () + 1;
	for (int i = 1; i <= m; ++i) a.id[i] = b.id[i] = i;
	for (int i : ac) t_sort (b, i);
	// print (b);
	attempt (a, 0);
	cout << best << '\n';
	for (int i : ac) cout << i << ' ';
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("sctab.inp", "r", stdin);
	freopen ("sctab.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}