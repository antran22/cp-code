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
const int prime_max = 1e7;
vi prime;
bool composite[prime_max + 1];
struct seg
{
	int l, r;
	seg () {}
	seg (int ll, int rr)
	{
		l = ll; r = rr;
	}
};
seg i[2][maxn];
seg *h = i[0], *g = i[1];
int id[maxn];
ll res[maxn];
order o[maxn];
int w1, w2, h1, h2;
void input ()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> w1 >> w2 >> h1 >> h2;
		w[i] = seg (w1, w2);
		h[i] = seg (h1, h2);
		id[i] = i;
		res[i] = 1;
	}
}
void sieve ()
{
	for (int i = 2; i <= prime_max; ++i)
	{
		if (composite[i]) continue;
		for (ll k = (ll)(i) * i; k <= prime_max; k += i)
			composite[k] = 1;
	}
	for (int i = 2; i <= prime_max; ++i)
		if (!composite[i]) prime.pb (i);
}
int get_prime_pow (int pr, int id)
{
	ll x = 1;
	sort (id + 1, id + n + 1, [] (int i, int j)
	{
		return
	})
	for (int i = 1; i <= n; ++i)
	{
		while (x * pr <= h[i]) x *= pr;
		if (x >= v) return x;
	}
}
void solve ()
{
	sieve ();

}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("teacareer.inp", "r", stdin);
	freopen ("teacareer.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << fixed << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}