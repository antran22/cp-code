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
const int inf = 1e9, maxn = 1e5 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
int n, k, m;
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
struct solution 
{
	int x[maxn], n, c, k;
	void input ()
	{
		FI (n), FI (c);
		for (int i = 1; i <= n; ++i)
			FI (k), x[i] = k;
		sort (x + 1, x + n + 1);
	}
	bool check (int d)
	{
		int res = 0, lx = -inf - 100;
		for (int i = 1; i <= n; ++i)
		{
			if (x[i] - lx >= d) ++res, lx = x[i];
		}
		return (res >= c);
	}
	void solve ()
	{
		int low = 0, high = 1e9;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (check (mid)) low = mid + 1;
			else high = mid - 1;
		}
		printf("%d\n", high);
	}
};
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("cow.inp", "r", stdin);
	freopen ("cow.out", "w", stdout);	
	int t;
	FI (t);
	for (int i = 1; i <= t; ++i)
	{
		solution gg;
		gg.input ();
		gg.solve ();
	}
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}