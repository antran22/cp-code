//code.cpp
#include <unistd.h>
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
const ld eps = 1e-9;
int n, k, m;
string problem = "A";
string current_dir;
void init ()
{
	char buff [FILENAME_MAX];
	getcwd (buff, FILENAME_MAX);
	current_dir = string (buff);
	current_dir += "/themis_format/" + problem + "/";

}
void solve ()
{

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	init ();
	solve ();
}