//code.cpp
#include <bits/stdc++.h>
using namespace std;
#define whole(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define ins insert
#define _(a) #a << " : " << (a)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18, maxx = 1e12 + 1;
const ld eps = 1e-9, pi = acos (-1);
ll n, k, m;
bool comp[maxn] = {};
vector <ll> prime;
void sieve ()
{
	int s = sqrt (maxn);
	prime.pb (0);
	for (int i = 2; i <= s; ++i)
	{
		if (!comp[i])
		{
			for (int j = i * i; j < maxn; j += i)
			{
				comp[j] = 1;
			}
		}
	}
	for (int i = 2; i < maxn; ++i)
		if (!comp[i]) prime.pb (i);
}
void input ()
{
	cin >> n;
	sieve ();
}
vector <pair <int, int>> sqf;
void in_ex (int id, ll val, int cnt)
{
	if (cnt > 0) sqf.pb (mp (val, cnt));	
	for (int i = id + 1; i < prime.size (); ++i)
	{
		if (val * prime[i] <= maxn)
		{
			in_ex (i, val * prime[i], cnt + 1);
		}
		else break;
	}
}
ll cnt (ll m)
{
	ll res = 0;
	for (auto x : sqf)
	{
		ll gg = ll (x.ft) * x.ft;
		if (gg > m) break;
		if (x.sd % 2) res += m / (gg);
		else res -= m / (gg);
	}
	return res;
}
void solve ()
{
	in_ex (0, 1, 0);
	sort (whole (sqf));
	ll l = 1, r = maxx;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (cnt (m) >= n) r = m - 1;
		else l = m + 1;
	}
	cout << l;
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("nonsquarefree.inp", "r", stdin);
	freopen ("nonsquarefree.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}