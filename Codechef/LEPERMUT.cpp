#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		bool good = true;
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			int Ai;
			cin >> Ai;
			if(abs(Ai - i) > 1) good = false;
		}
		cout << (good ? "YES" : "NO") << endl;
	}
	return 0;
}