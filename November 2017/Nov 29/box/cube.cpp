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
int n, k, m;
struct cube 
{
	int coord[3][2];
} c[51];
vi d[3];
int old_val[3][200];
int max_new [3] = {};
void input ()
{
	cin >> n >> k;
	vi val[3];
	for (int i = 1; i <= n; ++i)
	{
		for (int k = 0; k < 2; ++k)
		{
			for (int j = 0; j < 3; ++j)
			{
				cin >> c[i].coord[j][k];
				val[j].pb (c[i].coord[j][k]);
			}
		}
	}
	for (int i = 0; i < 3; ++i) 
	{
		sort (whole (val[i]));
		val[i].resize(unique(whole(val[i])) - val[i].begin ());
	}
	int t;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				t = lower_bound (whole (val[j]), c[i].coord[j][k]) - val[j].begin ();
				old_val[j][t] = c[i].coord [j][k];
				max_new [j] = max (max_new[j], t);
				c[i].coord[j][k] = t;
			}
		}
	}
/*	for (int i = 1; i <= n; ++i)
	{
		for (int k = 0; k < 2; ++k)
		{
			for (int j = 0; j < 3; ++j)
			{
				cout << c[i].coord[j][k] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}*/
	for (int j = 0; j < 3; ++j)
	{
		for (int i = 1; i < max_new[j]; ++i)
			d[j].pb (old_val[j][i] - old_val[j][i - 1]);
	}
}
int check[200][200][200];
void solve ()
{
	for (int i = 1; i <= n; ++i)
	{
		auto g = c[i].coord;
		for (int x = g[0][0]; x < g[0][1]; ++x)
			for (int y = g[1][0]; y < g[1][1]; ++y)
				for (int z = g[2][0]; z < g[2][1]; ++z)
				{
					++check [x][y][z];
				}
	}
	ll res = 0;
	for (int x = 0; x < max_new[0]; ++x)
		for (int y = 0; y < max_new[0]; ++y)
			for (int z = 0; z < max_new[0]; ++z)
			{
				if (check[x][y][z] >= k)
				{
					// res += (ll) (d[0][x]) * d[1][y] * d[2][z];
					cout << x << ' ' << y << ' ' << z << '\n';
				}
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
	freopen ("cube.inp", "r", stdin);
	freopen ("cube.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}