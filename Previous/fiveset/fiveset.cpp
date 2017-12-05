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
ll f[6][maxn] = {}, a[maxn], w[6];
ll x1, x2;
void input ()
{
	cin >> n >> x1 >> x2;
	w[1] = x1, w[2] = x2, w[3] = 1, w[4] = x2, w[5] = x1;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
}
void solve ()
{
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 1; j <= 5; ++j) f[j][i] = -inff;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= 5; ++j) f[j][i] = max (f[j - 1][i - 1] + w[j] * a[i], f[j][i - 1]);
	cout << *max_element (f[5] + 1, f[5] + n + 1);
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("fiveset.inp", "r", stdin);
	freopen ("fiveset.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}