#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

void assert(bool cond = false, string message = "Wrong answer") {
    if (!cond) return cout << "0.0" << endl, cerr << message << endl, exit(0);
}

int main(int argc, char * argv[])
{
    ifstream fin(argv[1]), fout(argv[2]);
    string S, ans;
    getline(fout, S);
    assert(S == "14e047d7a2907b9034950b074822b302", "Expected output got ???");
    getline(fout, S);
    getline(fin, ans);      
    assert(S == ans);
    int lim, used; fin >> lim; fout >> used;
    assert(used <= lim, "Too many questions asked");
    cout << "1.0\n"; cerr << "Correct!" << endl;
}
