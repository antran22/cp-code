#include "eval.h"
using namespace std;
string tmp;
string get_current_dir()
{
   char temp[1024];
   return ( getcwd(temp, 1024) ? string( temp ) : string("") );
}
string working_dir;
bool init (string current_dir)
{
	tmp = current_dir + "/eval_tmp";
	working_dir = current_dir;
	int g = system (("mkdir \"" + tmp + "\"").c_str ());
	if (g == -1) return 0;
	return 1;
}
void move_file_to_temp (string test_name, string problem)
{
	string test_dir = working_dir + "/problems/" + problem + "/" + test_name + "/" + problem;
	string prob = tmp + "/" + problem;
	int g = system (("cp \"" + test_dir + ".inp\" \"" + prob + ".inp\"").c_str ());
	g = system (("cp \"" + test_dir + ".out\" \"" + prob + ".out\"").c_str ());
}
void clean_up (string current_dir)
{
	int g = system (("rm -rf " + tmp).c_str ());
}