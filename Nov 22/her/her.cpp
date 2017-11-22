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
ll x = LONG_LONG_MAX;
ld milk = x, tea = x;
void input ()
{
	cin >> n;
}
void solve ()
{
	ld m = 0, t = 0;
	char g;
	for (int i = 1; i <= n; ++i)
	{
		milk /= 2;
		tea /= 2;
		m += milk;
		t += tea;
		cin >> g;
		if (g == 'M') milk += x;
		else tea += x;
	}
	if (m >= t) cout << "M";
	if (t >= m) cout << "H";
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("her.inp", "r", stdin);
	// freopen ("her.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}