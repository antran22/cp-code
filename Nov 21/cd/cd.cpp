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
int res[maxn], a[maxn], w, id[maxn];
void input ()
{
	cin >> n >> w;
	for (int i = 1; i <= n; ++i) cin >> a[i], id[i] = i;
	sort (id + 1, id + n + 1, [] (int i, int j)
	{
		return a[i] < a[j];
	});
}
void solve ()
{
	int i;
	int k = 0;
	for (i = 1; k + a[id[i]] <= w and i <= n; ++i) k += a[id[i]], res[id[i]] = 1;
	k = 0;
	for (; k + a[id[i]] <= w and i <= n; ++i) k += a[id[i]], res[id[i]] = 2;
	for (int i = 1; i <= n; ++i) cout << res[i] << ' ';
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("cd.inp", "r", stdin);
	freopen ("cd.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}