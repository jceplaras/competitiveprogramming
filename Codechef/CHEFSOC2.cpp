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

ull DP[1005][1005];
ull A[1005];

#define MOD 1000000007
int main() {

  int T;
  scanf("%d",&T);


  int N, M, S;
  while(T--) {
    scanf("%d %d %d",&N,&M,&S);

    FOR(i,1,M) {
      scanf("%d",&A[i]);
    }
    
    FORN(i,M+1)
    FOR(j,1,N) {
      DP[i][j] = 0;
    }
    DP[0][S] = 1;

    FOR(i,1,M) {
      FOR(j,1,N) {
        int left = j - A[i];
        if(left >= 1)
          DP[i][left] = (DP[i][left] + DP[i-1][j])%MOD;

        int right = j + A[i];
        if(right <= N)
          DP[i][right] = (DP[i][right] + DP[i-1][j])%MOD;
      }
    }

    FOR(i,1,N) {
      printf("%llu ",DP[M][i]);
    }
    printf("\n");
  }
  
  return 0;
}
