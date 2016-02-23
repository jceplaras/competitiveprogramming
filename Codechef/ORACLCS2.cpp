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
char str[105][101];

int main() {
  int T;
  int N,M;
  scanf("%d",&T);
  int minA = 0;
  int minB = 0;
  while(T--) {
    scanf("%d",&N);
    FORN(i,N) {
      scanf("%s",str[i]);
    }
    M=strlen(str[0]);
    minA = minB = M;

    FORN(i,N) {
    int countA = 0;
    int countB = 0;
      FORN(j,M) {
        if(str[i][j] == 'a') countA++;
        if(str[i][j] == 'b') countB++;
      }
    minA = min(minA,countA);
    minB = min(minB,countB);
    }

    printf("%d\n",min(minA,minB));
  }

  return 0;
}
