#include <bits/stdc++.h>
using namespace std;
#define whole(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define ins insert
#define ft first
#define sd second
#define _(a) #a << " : " << (a)
typedef long long ll;
typedef pair <int,int> pii;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m;
struct seg
{
	int l, r;
} a [maxn];
bool mark[maxn];
vi g;
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
	// cin >> n;
	read (n);
	for (int i = 1; i <= n; ++i)
		// cin >> a[i].l >> a[i].r;
		read (a[i].l), read (a[i].r);
	sort (a + 1, a + n + 1, [] (seg a, seg b)
	{
		return b.r > a.r;
	});
}
void solve ()
{
	for (int i = 1; i <= n; ++i)
	{
		int h = 0;
		for (int j : g)
		{
			if (j >= a[i].l and j <= a[i].r) ++h;
			if (h >= 2) break;
		}
		int p = a[i].r;
		while (h < 2)
		{
			if (mark[p]) --p;
			g.pb (p);
			mark[p] = 1;
			++h;
			--p;
		}
	}
	cout << g.size () << '\n';
	sort (whole (g));
	for (int i : g) cout << i << ' ';
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("advertise.inp", "r", stdin);
	freopen ("advertise.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}