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
typedef vector<ll> vll;
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
ll k, m, d, n;
void input ()
{
	cin >> n >> d;
}
vll div_list (ll n)
{
	vll res;
	ll s = sqrt (n);
	for (int i = 2; i <= s; ++i)
	{
		if (n % i != 0) continue;
		res.pb (i);
		res.pb (n / i);
	}
	res.pb (n);
	sort (whole (res));
	return res;
}
int count_m (ll n)
{
	int x = 0;
	while (true)
	{
		if (n < d or (n - d) % k) return x;
		else n = (n - d) / k, ++x;
	}
}
ll res, resk;
void solve ()
{
	vll h = div_list (n - d);
	for (ll i : h)
	{
		if (i <= d) continue;
		k = i;
		ll m = count_m (n);
		// cout << k << ' ' << m << '\n';
		if (m > res) res = m, resk = k;
	}
	if (resk < 2) resk = 2;
	cout << resk << ' ' << res;
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("teadream.inp", "r", stdin);
	// freopen ("teadream.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	// cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}