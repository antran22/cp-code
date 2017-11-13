#include "eval.h"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9;
string problem, current_dir;
int test_num, test_digit;
double point_per_test, total = 0;
bool input ()
{
	// cout << "problem name ? ";
	// cin >> problem;
	problem = "C";
	// cout << "number of test cases ? ";
	// cin >> test_num;
	test_num = 20;
	if (test_num == 0) return 0;
	point_per_test = 100.0 / test_num;
	test_digit = log10 (test_num);
	return 1;
}
string get_test_name (int test_id)
{
	stringstream ss;
	ss << test_id;
	string cnv_id = ss.str (), res = "test";
	int h = log10 (test_id);
	for (int i = h + 1; i <= test_digit; ++i)
		res += "0";
	res += cnv_id;
	return res;
}
/*void evaluate ()
{
	for (int i = 1; i <= test_num; ++i)
	{

	}
}*/
int main()
{
	if (!input ()) return 0;
	current_dir = get_current_dir ();
	if (!init (current_dir)) return 0;
	move_file_to_temp (get_test_name (14), problem);
	// clean_up (current_dir);
	return 0;
}