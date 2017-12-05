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
ll x, y;
int a[maxn];
void input ()
{
	cin >> n >> x >> y;
	for (int i = 1; i <= n; ++i) cin >> a[i];
}
ll check (int d)
{
	vector <ll> f(maxn, inff);
	ll ldel = -1;
	f[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		// cerr << a[i] << ' ';
		if ((a[i] - 1) % d == 0 or (a[i] + 1) % d == 0)
			f[i] = f[i - 1] + y;
		else if (a[i] % d == 0) f[i] = f[i - 1];
		if (ldel == -1) 
		{
			if (f[i - 1] + x < f[i]) f[i] = f[i - 1] + x, ldel = i;
		}
		else 
		{
			if (f[ldel] + (i - ldel) * x < f[i]) f[i] = f[ldel] + (i - ldel) * x, ldel = i;
		}
	}
	return f[n];
}
set <int> st;
void get_divisor (int n)
{
	int s = sqrt (n);
	for (int i = 1; i <= s; ++i)
	{
		if (n % i == 0) st.ins (i), st.ins (n / i);
	}
	st.erase (1);
}
void solve ()
{
	get_divisor (a[1]);
	get_divisor (a[n]);
	ll res = inff;
	for (int i : st)
	{
		res = min (res, check (i));
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
	freopen ("gcd_array.inp", "r", stdin);
	freopen ("gcd_array.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}