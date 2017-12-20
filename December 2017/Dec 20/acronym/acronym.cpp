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
int cnt[26] = {};
string s[maxn];
void input ()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s[i];
		++cnt[s[i][0] - 'a'];
	}
}
void solve ()
{
	int res = 0;
	for (int i = 1; i <= n; ++i)
	{
		--cnt[s[i][0] - 'a'];
		int scnt[26] = {};
		for (char c : s[i])
		{
			++scnt[c - 'a'];
		}
		bool ok = 1;
		for (int j = 0; j < 26; ++j)
		{
			if (scnt[j] > cnt[j]) 
			{
				ok = 0;
				break;
			}
		}
		if (ok) ++res;
		++cnt[s[i][0] - 'a'];
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
	freopen ("acronym.inp", "r", stdin);
	freopen ("acronym.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}