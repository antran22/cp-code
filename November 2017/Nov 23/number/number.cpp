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
string beg = "nil";
int neg_cnt = 0;
vector <string> pos;
void input ()
{
	cin >> n;
	string s;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s;
		if (s[0] == '-') 
		{
			neg_cnt++, beg = s;
			if (neg_cnt == 2 or s[1] == '0') 
			{
				cout << "NO";
				exit (0);
			}
		}
		else pos.pb (s);
	}
	sort (whole (pos), [] (string a, string b)
	{
		// cerr << a + b << ' ' << b + a << '\n';
		if (neg_cnt) return (a + b) > (b + a);
		else return (a + b) < (b + a);
	});
	for (string s : pos) cerr << s << '\n';
}
void solve ()
{
	int id;
	if (n == 1 and pos[0] == "0") 
	{
		cout << 0;
		return;
	}
	if (!neg_cnt)
	{
		for (int i = 0; i < pos.size (); ++i)
		{
			string s = pos[i];
			if (s[0] != '0') 
			{
				beg = s;
				id = i;
				break;
			}
		}
	}
	if (beg == "nil") 
	{
		cout << "NO";
		return;
	}
	cout << beg;
	for (int i = 0; i < pos.size (); ++i)
	{
		if (i == id) continue;
		string s = pos[i];
		cout << s;
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
	freopen ("number.inp", "r", stdin);
	freopen ("number.out", "w", stdout);
	input ();
	solve ();
	#ifdef tcva
	clock_t entime = clock ();
	cerr << "\nExecution time: " << double (entime - sttime) / CLOCKS_PER_SEC << "s";
	#endif
}