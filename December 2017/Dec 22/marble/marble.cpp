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
int n, k, m, hh[maxn], ww[maxn], w, h;
int f[601][601] = {};
void input ()
{
	cin >> w >> h >> n;
	for (int i = 1; i <= n; ++i) cin >> ww[i] >> hh[i];
}
void solve ()
{
	for (int i = 1; i <= h; ++i)
		for (int j = 1; j <= w; ++j)
		{
			f[i][j] = i * j;
			for (int it = 1; it <= n; ++it)
			{
				int ii = i - hh[it], jj = j - ww[it];
				if (ii < 0 or jj < 0) continue;
				f[i][j] = min (f[i][j], f[i][jj] + f[ii][ww[it]]);
				f[i][j] = min (f[i][j], f[ii][j] + f[hh[it]][jj]);
			}
		}
	cout << f[h][w];
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("marble.inp", "r", stdin);
	freopen ("marble.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}