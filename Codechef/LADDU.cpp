#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORN(i,N) for (int i = 0; i < N; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)


using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int main() {
  int T;
  cin >> T;
  while(T--) {
    int totalScore = 0;
    int N;
    string isIndian;

    cin >> N;
    cin >> isIndian;

    string str;
    while(N--) {
      cin >> str;
      if(str.compare("CONTEST_WON") == 0) {
        int rank;
        cin >> rank;

        totalScore += 300;
        if(rank <= 20)
          totalScore += (20 - rank);
      }
      else if(str.compare("TOP_CONTRIBUTOR") == 0) {
        totalScore += 300;
      }
      else if(str.compare("BUG_FOUND") == 0) {
        int severe;
        cin >> severe;
        totalScore += severe;
      }
      else if(str.compare("CONTEST_HOSTED") == 0) {
        totalScore += 50;
      }
    }

    if(isIndian.compare("INDIAN") == 0) {
      cout << totalScore/200 << endl;
    }
    else {
      cout << totalScore/400 << endl;
    }

  }
  
  return 0;
}
