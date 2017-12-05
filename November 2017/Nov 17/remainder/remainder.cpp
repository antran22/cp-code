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
ll n, x, m;
void FI(ll &x)
{
    register int c = getchar();
    x = 0;
    bool neg = 0;
    for(;(c < 48 or c > 57) && c != '-';c = getchar());
    if (c == '-') neg = 1, c = getchar();
    for(; c > 47 && c < 58;c = getchar()) x = (x<<1) + (x<<3) + c - 48;
    if(neg) x = -x;
}
void input ()
{
	FI (x);
	FI (n);
	FI (m);
	// cin >> x >> n >> m;
}
int digitnum (ll a)
{
	return floor (log10 (a)) + 1;
}
ull mull (ll x, ll y)
{
	ld t = ld (x) * y / m;
	ll q = t;
	ll r = (x * y - q * m) % m;
	if (r < 0) r += m;
	return r;
}
ull mul_mod (ull a, ull b)
{
	if (a > m) a %= m;
	if (b > m) b %= m;
	if (a < b) swap (a, b);
	return mull (a, b);
}
// unordered_map <ull, ull> p10;
// auto it = p10.end ();
ull pow_mod (ull b)
{
	// it = p10.find (b);
	// if (it != p10.end ()) return it -> second;
	if (b == 0) return 1 % m;
	ull x = pow_mod (b >> 1);
	x = mul_mod (x, x);
	if (b & 1) x = (ull (x) * 10) % m;
	// p10.ins (mp (b, x));
	return x;
}
ull join_num (ull a, ull b, ull numb)
{
	ull x = mul_mod (a, pow_mod (numb));
	return (x + b) % m;
}
ull num;
ull concat_mod (ull a, ull b)
{
	if (b == 1) return a % m;
	ull x = concat_mod (a, b >> 1);
	x = join_num (x, x, num * (b >> 1));
	if (b & 1) x = join_num (x, a, num);
	return x;
}
void solve ()
{
	// cerr << x << ' ' << n << ' ' << m << '\n';
	// p10.clear ();
	num = digitnum (x);
	printf("%lld\n", concat_mod (x, n));
	// cout << pow_mod (x, n);
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("remainder.inp", "r", stdin);
	freopen ("remainder.out", "w", stdout);
	ll t;
	FI (t);
	for (int i = 1; i <= t; ++i)
	{
		input ();
		solve ();
	}
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}