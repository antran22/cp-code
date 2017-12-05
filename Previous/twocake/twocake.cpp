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
int posa[maxn], posb[maxn];
vi _d[2 * maxn + 1];

void input ()
{
	vi *d = _d[maxn];
	unordered_set dl;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i], posa[a[i]] = i;
	for (int i = 1; i <= n; ++i) cin >> b[i], posb[b[i]] = i;
	for (int i = 1; i <= n; ++i)
		d[posa[i] - posb[i]].pb (posa[i]), dl.ins (posa[i] - posb[i]);
	for (int i : dl) sort (whole (d[i]));
}
int f[maxn];
int find (int dif, int v)
{
	auto g = lower_bound (whole (d[dif]), v);
	if (g == d[dif].end ()) return 0;
	return *g;
}
void check (int x)
{
	int dif = posa[x] - posb[x];
	int i = find (dif + 1, posa[x]);
	int j = find (dif - 1, posa[x]);
	int k, h;
	if (i == -1) k = n + 1z
}
void solve ()
{
	f[0] = inf;
	for (int i = n; i >= 1; --i)
	{

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
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}