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
int a[maxn], cnt[maxn], v[maxn];
vi adj[maxn];
int f[maxn], g[maxn];
void input ()
{
	vi val;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i], val.pb (a[i;
	sort (whole (val));
	int x;
	for (int i = 1; i <= n; ++i)
		x = lower_bound (whole (val), a[i]) - val.begin + 1, v[x] = a[i], cnt[x] ++, a[i] = x;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j)
		{
			int dif = (v[a[i]] - v[a[j]]);
			if (dif == 1 or dif == 8 or dif == 9) adj[a[i]].pb (a[j]);
		}
}
void solve ()
{
	for (int i = 1; i <= n; ++i)
}	
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("SEG198.inp", "r", stdin);
	freopen ("SEG198.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}