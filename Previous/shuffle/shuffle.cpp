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
int n, k, m, a[maxn] = {}, b[maxn] = {};
void input ()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> b[i];
}
vi cycle [maxn];
int cid [maxn], cp[maxn], cs[maxn];
int ccnt = 0;
void get_cycle (int i)
{
	vi &tc = cycle [++ccnt];
	tc.pb (0);
	int j = i;
	do
	{
		cid[j] = ccnt;
		cp[j] = tc.size ();
		tc.pb (j);
		j = a[j];
	} while (j != i);
	cs[ccnt] = tc.size () - 1;
}
int get_dist (int i, int j)
{
	if (cp[i] <= cp[j]) return cp[j] - cp[i];
	else return cs[cid[i]] - (cp[i] - cp[j]);
}
int nprime [maxn] = {};
void sieve ()
{
	for (int i = 2; i < maxn; ++i)
		for (ll j = ll(i) * i; j < maxn; j += i)
			if (nprime[j] == 0) nprime[j] = i;
	for (int i = 1; i < maxn; ++i)
		if (nprime[i] == 0) nprime[i] = i;
}
// vector <pair <int, int>> vietan;
vi dibs (maxn, -1);
void factorize (int x, int k)
{
	int lprime = 1;
	while (x != 1)
	{
		int j = nprime[x];
			// vietan.pb (mp (k % j, j));
		lprime *= j;
		if (dibs[lprime] != -1 and dibs[lprime] != k % lprime)
		{
			cout << "NIE";
			exit (0);
		}
		else dibs[lprime] = k % lprime;
		x /= j;
	}
}
void solve ()
{
	sieve ();
	for (int i = 1; i <= n; ++i)
		if (!cid[i]) get_cycle (i);
	for (int i = 1; i <= n; ++i)
	{
		if (cid[i] != cid[b[i]])
		{
			cout << "NIE";
			exit (0);
		}
		int k = get_dist (i, b[i]);
		factorize (cs[cid[i]], k);
	}
	cout << "TAK";
	// for (auto g : vietan) cout << g.first << ' ' << g.second << '\n';
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	freopen ("shuffle.inp", "r", stdin);
	freopen ("shuffle.out", "w", stdout);
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