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
#include <climits>

#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORN(i,N) for (int i = 0; i < N; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)


using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int values[32768];

int main() {
  int N;

  while(scanf("%d",&N)!=-1) {
    int corners = 1 << N;
    int maxVal = INT_MIN;
    int weight, neighbor, nN;
    fill_n(values,corners,0);
    FORN(i,corners) {
      int weight;
      scanf("%d",&weight);

      FORN(s,N) {

        neighbor = 1 << s;

        nN = i ^ neighbor;
        values[nN]+=weight;
      }
    }
    FORN(i,corners) {
      FORN(s,N) {
        neighbor = 1 << s;

        nN = i ^ neighbor;
        maxVal = max(maxVal,values[i]+values[nN]);
      }
    }
    printf("%d\n",maxVal);
  }

  return 0;
}
