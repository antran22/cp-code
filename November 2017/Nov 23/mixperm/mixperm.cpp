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
const int inf = 1e9, maxn = 1e4 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m;
vi a, b;
void read(int &x)
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
	read (n);
	a.resize (maxn, 0);
	b.resize (maxn, 0);
	for (int i = 1; i <= n; ++i)
		read (k), a[i] = k;
	for (int i = 1; i <= n; ++i)
		read (k), b[i] = k;
}
bool bf[maxn][maxn], af[maxn][maxn], cf[maxn][maxn];
void cal_bf ()
{
	bool cntb[maxn] = {};
	for (int i = 1; i <= n; ++i)
	{
		bool cnta[maxn] = {};
		for (int j = i; j <= n; ++j)
		{
			if (cnta[a[j]] or cntb[a[j]]) break;
			cnta[a[j]] = 1;
			bf[i][j] = 1;
		}
		if (cntb[b[i]]) break;
		cntb[b[i]] = 1;
	}
}
void cal_af ()
{
	bool cntb[maxn] = {};
	for (int i = n; i >= 1; --i)
	{
		bool cnta[maxn] = {};
		for (int j = i; j >= 1; --j)
		{
			if (cnta[a[j]] or cntb[a[j]]) break;
			cnta[a[j]] = 1;
			af[j][i] = 1;
		}
		if (cntb[b[i]]) break;
		cntb[b[i]] = 1;
	}
}
void cal_cf ()
{
	bool cntb[maxn] = {};
	for (int i = 1; i <= n; ++i)
	{
		bool cnta[maxn] = {};
		for (int j = n + 1; j >= i; --j)
		{
			if (cnta[b[j]] or cntb[b[j]]) break;
			cnta[b[j]] = 1;
			cf[i][j - 1] = 1;
		}
		if (cntb[b[i]]) break;
		cntb[b[i]] = 1;
	}
}
int res = 0;
bool out[maxn][maxn];
void solve ()
{
	cal_af ();
	cal_bf ();
	cal_cf ();
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
		{
			if (af[i][j] and bf[i][j] and cf[i][j]) out[i][j] = 1;
			af[i][j] = bf[i][j] = cf[i][j] = 0;
		}
	swap (a, b);
	cal_af ();
	cal_bf ();
	cal_cf ();
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			if (af[i][j] and bf[i][j] and cf[i][j]) out[i][j] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j) if (out[i][j]) res++;
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
	freopen ("mixperm.inp", "r", stdin);
	freopen ("mixperm.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}