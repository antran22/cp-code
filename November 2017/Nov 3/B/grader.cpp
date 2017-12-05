#include "grader.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

static std::string s;
static int tests;

bool make_test(std::string p) {
	tests++;
	for (int i = 0; i < p.size(); i++) {
		if (p[i] != '0' && p[i] != '1') {
			return false;
		}
	}
	std::string ss = p + "#" + s;
	std::vector<int> pr(ss.size() + 1);
	pr[0] = -1;
	bool answer = false;
	for (int i = 1; i <= ss.size(); i++) {
		int k = pr[i - 1];
		while (k >= 0 && ss[k] != ss[i - 1])
			k = pr[k];
		pr[i] = k + 1;
		if (pr[i] == p.size()) {
			answer = true;
			break;
		}
	} 
	return answer;
}

int main() {
    int t;
    std::cin >> s >> t;
    std::string ans = guess(s.size(), t);
    // BEGIN SECRET
    puts("14e047d7a2907b9034950b074822b302");
    // END SECRET
	std::cout << ans << std::endl << tests << std::endl;
    return 0;
}
