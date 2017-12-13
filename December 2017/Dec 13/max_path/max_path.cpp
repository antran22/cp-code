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
typedef pair <int,int> pii;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e5 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m;
ll a[4][maxn];
int state [14] = {0, 3, 7, 7, 6, 7, 7, 4, 2, 1, 6, 7, 3, 3};
vi adj[14] = {
				{},
				{9, 11, 12, 13},
				{9, 11, 12, 13},
				{3, 5},
				{8, 1, 10},
				{9, 11, 12, 13},
				{3, 5},
				{7, 2, 4, 6},
				{8, 1, 10},
				{9, 11, 12, 13},
				{7, 2, 4, 6},
				{7, 2, 4, 6},
				{3},
				{8, 1, 10}
			};
ll f[maxn][14];
void input ()
{
	cin >> n;
	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 1; j <= 13; ++j)
		{
			f[i][j] = -inff;
		}
	}
}
bool get_bit (int i, int j)
{
	return (i >> j) & 1;
}
ll get_sum (int i, int k)
{
	ll res = 0;
	for (int j = 0; j < 3; ++j)
	{
		if (get_bit (k, j)) res += a[3 - j][i];
	}
	return res;
}
void solve ()
{
	f[0][7] = f[0][10] = f[0][11] = 0;
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 1; j <= 13; ++j)
		{
			for (int k : adj[j])
			{
				f[i + 1][k] = max (f[i + 1][k], f[i][j] + get_sum (i + 1, state [k]));
			}
		}
	}
	cout << f[n + 1][9];
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("max_path.inp", "r", stdin);
	freopen ("max_path.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}