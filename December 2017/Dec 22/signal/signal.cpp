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
int max1[maxn], max2[maxn], a[maxn];
void input ()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		max1[i] = max (max1[i - 1], a[i]);
	}
	for (int i = n; i >= 1; --i)
	{
		max2[i] = max (max2[i + 1], a[i]);
	}
}
void solve ()
{
	int res = -1;
	for (int i = 2; i < n; ++i)
	{
		int x = max1[i - 1] - a[i], y = max2[i + 1] - a[i];
		if (x >= k and y >= k)
		{
			res = max (res, x + y);
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
	freopen ("signal.inp", "r", stdin);
	freopen ("signal.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}