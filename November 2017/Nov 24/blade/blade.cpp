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
int n, k, a[maxn];
ll m;
void FI(int &x)
{
    register int c = getchar();
    x = 0;
    bool neg = 0;
    for(;(c < 48 or c > 57) && c != '-';c = getchar());
    if (c == '-') neg = 1, c = getchar();
    for(; c > 47 && c < 58;c = getchar()) x = (x<<1) + (x<<3) + c - 48;
    if(neg) x = -x;
}
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
	// cin >> n >> m;
	FI (n);
	FI (m);
	for (int i = 1; i <= n; ++i) FI (k), a[i] = k;
}
ll cnt (int h)
{
	ll res = 0;
	for (int i = 1; i <= n; ++i) res += max (0, a[i] - h);
	return res;
}
void solve ()
{
	int l = 0, h = 1e9;
	while (l <= h)
	{
		int mid = (l + h) / 2;
		ll x = cnt (mid);
		if (x >= m) l = mid + 1;
		else h = mid - 1;
	}
	cout << h;
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	freopen ("blade.inp", "r", stdin);
	freopen ("blade.out", "w", stdout);
	cin.tie (NULL);
	cout.tie (NULL);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}