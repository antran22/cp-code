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
typedef pair<int,string> pii;
#define occ first
#define str second
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9;
int n, k, m;
deque <string> x[26];
void input ()
{
	cin >> n >> m;
	string s;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s;
		x[s[0] - 'a'].pb (s);
	}
	for (int i = 0; i < 26; ++i)
		sort (whole (x[i]));
}
void solve ()
{
	char c;
	for (int i = 1; i <= m; ++i)
	{
		cin >> c;
		int g = c - 'a';
		string s = x[g].front ();
		cout << s << '\n';
		x[g].pop_front ();
		x[g].pb (s);
	}
}
int main()
{
	#ifdef tcva
	clock_t sttime = clock ();
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	// freopen ("zigzag.inp", "r", stdin);
	// freopen ("zigzag.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}