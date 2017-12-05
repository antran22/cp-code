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
ll a[maxn], sum[maxn];
int cnt[maxn];
void input ()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
		if (a[i] < 0) cnt[i] = cnt[i - 1] + 1;
		else cnt[i] = cnt[i - 1];
	}
}
deque <int> dq;
void solve ()
{
	ll res = 0;
	dq.push_back (0);
	for (int i = 1; i <= n; ++i)
	{
		while (dq.size () and cnt[i] - cnt[dq.front ()] > k) 
			dq.pop_front ();
		// cout << dq.front () << ' ';
		res = max (res, sum[i] - sum[dq.front()]);
		while (dq.size () and sum[dq.back ()] >= sum[i]) dq.pop_back ();
		dq.push_back (i);
	}
	cout << res << '\n';
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("checkpoint.inp", "r", stdin);
	freopen ("checkpoint.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}