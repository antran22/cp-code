#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "convexhull";
// Số test kiểm tra
const int NTEST = 100;

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h)
{
    return l + rand () % (h - l + 1);
}

int main()
{
    srand(time(NULL));
    for(int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        // Code phần sinh test ở đây
        int n = Rand (10, 20);
        // int n = 18;
        inp << n << '\n';
        for (int i = 1; i <= n; ++i)
            inp << Rand (-10, 10) << ' ' << Rand (-10, 10) << '\n';
        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system(("./" + NAME).c_str());
        system(("./" + NAME + "_trau").c_str());
        // Nếu dùng linux thì thay fc bằng diff
        if(system(("diff " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}